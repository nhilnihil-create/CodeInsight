#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
int main(){
    int D, G;
    cin >> D >> G;
    vector<int> p(D);
    vector<int> c(D);
    int ans = 1e9;
    for(int i = 0; i < D; i++) cin >> p.at(i) >> c.at(i);
    for(int i = 0; i < (1 << D); i++){
        int score = 0, take = 0, reset_max = -1;
        for(int j = 0; j < D; j++){
            if(i & (1 << j)){
                score += 100 * (j+1) * p.at(j) + c.at(j);
                take += p.at(j);
            }else{
                reset_max = j + 1;
            }
        }
        if(score < G){
            int n = 100 * reset_max;
            int n_1 = (G - score) % n;
            int n_2 = (G - score) / n;
            if((n_1 == 0 ? n_2 : n_2 + 1) >= p.at(reset_max - 1)) continue;
            take += n_1 == 0 ? n_2 : n_2 + 1;
        }
        if(take < ans) ans = take;
    }
    cout << ans << endl;
    return 0;
}


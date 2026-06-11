#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    int k, s, p;
    cin >> N >> M;
    vector<vector<int>> light(M);
    vector<int> P;
    for (int i = 0; i < M; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> s;
            light.at(i).push_back(s);
        }
    }
    for (int i = 0; i < M; i++){
        cin >> p;
        P.push_back(p);
    }
    int ans = 0;
    bool all_on;
    for (int bit = 0; bit < (1 << N); bit++){
        all_on = true;
        for (int i = 0; i < M; i++){
            int on = 0;
            for (int j = 0; j < light.at(i).size(); j++){
                if (bit & (1 << light.at(i).at(j) - 1)){
                    on += 1;
                }
            }
            if (on % 2 != P.at(i)){
                all_on = false;
            }            
        }
        if (all_on){
            ans += 1;
        }
    }
    cout << ans << endl;
}
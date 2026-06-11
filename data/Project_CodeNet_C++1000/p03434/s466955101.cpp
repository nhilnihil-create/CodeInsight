#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);

    rep2(i, 0, N) cin >> a.at(i);

    int temp;
    rep2(i, 0, N){
        rep2(j, 0, N-1-i){
            if(a.at(j) < a.at(j+1)){
                temp = a.at(j);
                a.at(j) = a.at(j+1);
                a.at(j+1) = temp;
            }
        }
    }

    int score_dif = 0;
    rep2(i, 0, N){
        if(i % 2 == 0) score_dif += a.at(i);
        if(i % 2 == 1) score_dif -= a.at(i);
    }

    cout << score_dif << endl;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    int f[n][10];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> f[i][j];
        }
    }

    ll p[n][11];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            cin >> p[i][j];
        }
    }

    ll ans = -10e8-1;
    for (int bit = 0; bit < (1<<10); ++bit) {
        vector<int> S;
        for (int i = 0; i < 10; ++i) {
            if (bit & (1<<i)) {
                S.push_back(i);
            }
        }

        int cou = 0;
        ll now = 0;
        if(S.size() != 0){
            for(int i = 0; i < n; i++){
                cou = 0;
                for(int j = 0; j < S.size(); j++){
                    if(f[i][S[j]] == 1){
                        cou++;
                    }
                }

                now += p[i][cou];
            }

            if(now > ans){
                ans = now;
            }
        }
    }

    cout << ans << endl;
}
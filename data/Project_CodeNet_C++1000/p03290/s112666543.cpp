#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int kam[15], c[15];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int d, g;
    cin >> d >> g;
    ll ans = 1e9;
    for(int i = 0; i < d; i++) cin >> kam[i] >> c[i];
    for(int i = 0; i < (1 << d); i++){
        ll score = 0, solved = 0;
        for(int j = 0; j < d; j++){
            if(i >> j & 1){
                score += kam[j] * 100LL * (j + 1) + c[j];
                solved += kam[j];
            }
        }
        for(int j = d - 1; j >= 0; j--){
            if(i >> j & 1) continue;
            if(score >= g) break;
            int need = g - score;
            int z = min(kam[j], need / (100 * (j + 1)));
            score += z * 100 * (j + 1);
            solved += z;
        }
        if(score >= g) ans = min(ans, solved);
    }
    cout << ans;

    return 0;
}

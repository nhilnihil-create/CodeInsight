#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e2+5;

int n;
bool f[N][6][3];
int p[N][11];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            for(int k = 1; k <= 2; k++){
                cin >> f[i][j][k];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 10; j++){
            cin >> p[i][j];
        }
    }
    ll ans = -2e18;
    for(int mask = 1; mask < (1 << 10); mask++){
        ll cnt = 0 , open = 0;
        for(int i = 1; i <= n; i++){
            ll C = 0;
            for(int j = 0 , X = 1; j < 20; j += 2 , X++){
                C += ( (mask & (1 << j)) > 0 && f[i][X][1]);
                C += ( (mask & (1 << (j + 1))) > 0 && f[i][X][2]);
            }
            if(C >= 1)
                open ++;
            cnt += p[i][C];
        }
        if(open >= 1)
            ans = max(ans , cnt);
    }
    cout << ans << "\n";
}

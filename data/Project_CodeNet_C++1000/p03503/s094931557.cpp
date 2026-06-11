#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

bool flag[100][10];
int val[100][11];
int main()
{
    cin >> N;
    rep(i, N){
        rep(j, 10){
            cin >> flag[i][j];
        }
    }
    rep(i, N){
        rep(j, 11){
            cin >> A;
            val[i][j] = A;
        }
    }
    ll ans = INF;
    rep(i, pow(2, 10)){
        if(i == 0) continue;
        ll profit = 0;
        rep(j, N){
            int curr = i;
            int cnt = 0;
            rep(k, 10){
                if(curr%2 == 1 && flag[j][k] == 1) cnt++;
                curr /= 2;
            }
            profit += val[j][cnt];
        }
        ans = max(ans, profit);
    }
    cout << ans;
}

#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;
typedef pair<Pa, ll> info;

int main() {
    cin >> N;
    string s;
    cin >> s;
    ll cnt = 0;
    rep(i, N-1){
        if(s[i+1] == 'E') cnt++;
    }
    ll ans = cnt;
    rep(i, N-1){
        if(s[i] == 'W') cnt++;
        if(s[i+1] == 'E') cnt--;
        ans = min(ans, cnt);
    }
    cout << ans;
}

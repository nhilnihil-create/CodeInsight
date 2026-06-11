#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;
	
int main()
{
    cin >> N >> K;
    ll ans = 0;
    for(ll b=K+1;b<=N;b++){
        ans += N/b * max(0ll, b-K) + max(0ll, N%b - max(K - 1, 0ll));
    }
    cout << ans;
}

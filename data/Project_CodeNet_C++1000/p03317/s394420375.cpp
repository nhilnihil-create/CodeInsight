#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

int main() {
    cin >> N >> K;
    rep(i, N){
        cin >> A;
    }
    if(N == K) cout << 1;
    else cout << ((N-K-1)/(K-1)+1)+1;
}

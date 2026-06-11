#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;


Pa arr[100000];
int main() {
	cin >> N >> M;
	ll cnt = 0;
	rep(i, M) {
        cin >> A >> B;
        arr[i] = Pa(B, A);
	}
    sort(arr, arr+M);
    ll prev = -1;
    rep(i, M){
        if(prev <= arr[i].second) {
            prev = arr[i].first;
            cnt++;
        }
    }
    cout << cnt;
}

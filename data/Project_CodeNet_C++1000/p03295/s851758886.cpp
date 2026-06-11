#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

Pa arr[100000];
int main() {
	cin >> N >> M;
	rep(i, M){
		cin >> A >> B;
		arr[i] = Pa(B, A);
	}
	sort(arr, arr+M);
	int curr = -1, cnt = 0;
	rep(i, M){
		if(curr <= arr[i].second){
			curr = arr[i].first;
			cnt++;
		}
	}
	cout << cnt;
}

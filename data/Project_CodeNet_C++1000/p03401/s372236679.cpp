#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

int arr[100000];
int main() {
	cin >> N;
	ll cost = 0;
	int prev = 0;
	rep(i, N){
		cin >> arr[i];
		cost += abs(prev - arr[i]);
		prev = arr[i];
	}
	cost += abs(prev);
	vector<int> pos;
	pos.push_back(0);
	rep(i, N){
		pos.push_back(arr[i]);
	}
	pos.push_back(0);

	rep(i, N){
		cout << cost - abs(pos[i] - pos[i+1]) - abs(pos[i+1] - pos[i+2]) + abs(pos[i] - pos[i+2]) << endl;	
	}
}


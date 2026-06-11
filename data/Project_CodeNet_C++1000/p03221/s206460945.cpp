#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

vector<int> arr[100001];
Pa info[100001];

string int_tostring(int i){
    string in = to_string(i);
    string s = "000000";
    rep(j, in.size()){
        s[6-in.size()+j] = in[j];
    }
    return s;
}

int main() {
	cin >> N >> M;
	rep(i, M) {
		cin >> A >> B;
		info[i] = Pa(A, B);
		arr[A].push_back(B);
	}

	rep(i, N+1) {
		sort(arr[i].begin(), arr[i].end());
	}

	rep(i, M) {
		cout << int_tostring(info[i].first);
        cout << int_tostring(lower_bound(arr[info[i].first].begin(), arr[info[i].first].end(), info[i].second) - arr[info[i].first].begin() + 1) << endl;
	}
}

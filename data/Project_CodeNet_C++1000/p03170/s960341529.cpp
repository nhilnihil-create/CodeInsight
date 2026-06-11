#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

char game(int K, vector<int> &a, vector<int> &in_set, vector<char> &state) {
	if (state[K] != 'X') return state[K];
	if (in_set[K]) {
		state[K] = 'W';
		return 'W';
	}
	char curr_state = 'L';
	for (int i = 0; i < a.size(); i++) {
		if (K - a[i] >= 0 && game(K - a[i], a, in_set, state) == 'L') {
			curr_state = 'W';
			break;
		}
	}
	state[K] = curr_state;
	return curr_state;
}

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {
		
	// }
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> in_set(k + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		in_set[a[i]]++;
	}
	vector<char> state(k + 1, 'X');
	state[0] = 'L';
	char ans = game(k, a, in_set, state);
	if (ans == 'W') {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}

	return 0;
}
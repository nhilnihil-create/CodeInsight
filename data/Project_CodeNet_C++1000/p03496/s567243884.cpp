#include <bits/stdc++.h>
 
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}
 
void pos(vector<int> &A) {
	int N = A.size();
	for(int i = 0; i < N - 1; i++) {
		cout << i + 1 << " " << i + 2 << endl;
	}
}

void neg(vector<int> &A) {
	int N = A.size();
	for(int i = N; i >= 2; i--) {
		cout << i << " " << i - 1 << endl;
	}
}

void solve() {
	int N;
	cin >> N;
	vector<int> A(N);
	
	bool positive = false, negative = false;
	int mi = 0, ma = 0;
	int mi_i = 0, ma_i = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] > 0) {
			positive = true; 
			if (ma < A[i]) {
				ma = A[i];
				ma_i = i;
			}
		}
		if (A[i] < 0) {
			negative = true; 
			if (mi > A[i]) {
				mi = A[i];
				mi_i = i;
			}
		}
	}

	if (!positive && !negative) {
		cout << 0 << endl;
		return;
	}
	if (positive && !negative) {
		cout << N - 1 << endl;
		pos(A);
	} else if (!positive && negative) {
		cout << N - 1 << endl;
		neg(A);
	} else {
		if (abs(mi) > abs(ma)) {
			cout << 2 * N - 1 << endl;
			for(int i = 0; i < N; i++) {
				cout << mi_i + 1 << " " << i + 1 << endl;
			}
			neg(A);
		} else {
			cout << 2 * N - 1 << endl;
			for(int i = 0; i < N; i++) {
				cout << ma_i + 1 << " " << i + 1 << endl;
			}
			pos(A);
		}

	}



}

int main() {
    #ifdef LOCAL_ENV
    cin.exceptions(ios::failbit);
    #endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    
    solve();
}
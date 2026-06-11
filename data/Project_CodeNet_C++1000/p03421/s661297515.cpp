#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

ll N, A, B;

int main(){
	cin >> N >> A >> B;
	if (A + B <= N + 1 && N <= A*B) {
		vector<int>v(B + 1, 0);
		vector<vector<int>>u(B);
		int t = N;
		for (int i = 0; i < B; ++i) {
			int k = min(A, t - (B - i - 1));
			v[i] = k;
			t -= k;
		}
		int p = 0;
		for (int i = N; i; --i) {
			u[p].push_back(i);
			--v[p];
			++p;
			if (!v[p])p = 0;
		}
		for (int i = 0; i < B; ++i) {
			for (int j = u[i].size() - 1; j >= 0; --j) {
				cout << u[i][j] << sp;
			}
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
		return 0;
	}
	return 0;
}
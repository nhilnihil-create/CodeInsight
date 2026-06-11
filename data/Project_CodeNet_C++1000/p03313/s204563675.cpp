#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, A, S;
set<pair<int,int>>st[1 << 18];
int main() {
	cin >> N;
	for (int i = 0; i < (1 << N); ++i) {
		cin >> A;
		st[i].insert(mkp(A, i));
		st[i].insert(mkp(-1, -1));
	}
	for (int i = 1; i < (1 << N); ++i) {
		for (int j = 0; j < N; ++j) {
			if (i&(1 << j)) {
				auto it = st[i - (1 << j)].begin();
				st[i].insert(*it);
				++it;
				st[i].insert(*it);
				while (st[i].size() > 2) {
					st[i].erase(st[i].begin());
				}
			}
		}
	}
	for (int i = 1; i < (1 << N); ++i) {
		int t = 0;
		for (auto j : st[i]) {
			t += j.first;
		}
		S = max(S, t);
		cout << S << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

class myComparator {
public: 
	int operator() (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin >> n >> m;
	int a[n];
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<pair<int, int>> bc(m);
	for (int i = 0; i<m; i++) {
		int b,c; cin >> b >> c;
		bc[i] = make_pair(b, c);
	}
	sort(a, a+n);
	sort(bc.begin(), bc.end(), myComparator());
	ll curr_ret = 0;
	int ptr1 = 0, ptr2 = 0;
	for (int i = 0; i<m && ptr1 < n; i++) {
		if (a[ptr1] < bc[i].second) {
			ptr2 = ptr1;
			while (ptr2 < n && a[ptr2] < bc[i].second && bc[i].first > 0) {
				a[ptr2] = bc[i].second; 
				ptr2++;
				bc[i].first--;
			}
			ptr1 = ptr2;
		}
	}
	for (int i = 0; i<n; i++) curr_ret += a[i];
	cout << curr_ret << '\n';
}


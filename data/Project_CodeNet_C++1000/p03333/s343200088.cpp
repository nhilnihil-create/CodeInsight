#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, L[100000], R[100000], p;
bool b[100000];
ll c1, c2;
vector<pair<int, int>>r, l;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> L[i] >> R[i];
		l.push_back(mkp(R[i], i));
		r.push_back(mkp(L[i], i));
	}
	sort(l.begin(), l.end());
	sort(r.rbegin(), r.rend());
	for (int i = 0; i < N; ++i) {
		if (!b[l[i].second]) {
			b[l[i].second] = true;
			if (p - l[i].first > 0) {
				c1 += p - l[i].first;
				p = l[i].first;
			}
		}
		if (!b[r[i].second]) {
			b[r[i].second] = true;
			if (r[i].first - p > 0) {
				c1 += r[i].first - p;
				p = r[i].first;
			}
		}
	}
	c1 += abs(p);
	memset(b, false, sizeof b);
	p = 0;
	for (int i = 0; i < N; ++i) {
		if (!b[r[i].second]) {
			b[r[i].second] = true;
			if (r[i].first - p > 0) {
				c2 += r[i].first - p;
				p = r[i].first;
			}
		}
		if (!b[l[i].second]) {
			b[l[i].second] = true;
			if (p - l[i].first > 0) {
				c2 += p - l[i].first;
				p = l[i].first;
			}
		}
	}
	c2 += abs(p);
	cout << max(c1, c2) << endl;
}
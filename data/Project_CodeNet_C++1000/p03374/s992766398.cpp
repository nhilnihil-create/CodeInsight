#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int N;
ll C, x[100002], v[100002], MAX;
lP r[100002], l[100002], r2[100002], l2[100002];

int main(){
	cin >> N >> C;
	for (int i = 1; i != N + 1; ++i) {
		cin >> x[i] >> v[i];
	}
	x[N + 1] = C;
	for (int i = 1; i != N + 2; ++i) {
		r[i].first = r[i - 1].first + v[i] - x[i] + x[i - 1];
		r2[i].first = r2[i - 1].first + v[i] + (x[i - 1] - x[i]) * 2;
		r[i].second = max(r[i].first, r[i - 1].second);
		r2[i].second = max(r2[i].first, r2[i - 1].second);
	}
	for (int i = N; i != -1; --i) {
		l[i].first = l[i + 1].first + v[i] - x[i + 1] + x[i];
		l2[i].first = l2[i + 1].first + v[i] + (x[i] - x[i + 1]) * 2;
		l[i].second = max(l[i].first, l[i + 1].second);
		l2[i].second = max(l2[i].first, l2[i + 1].second);
	}
	for (int i = 0; i != N + 1; ++i) {
		MAX = max({ MAX,r[i].second + l2[i + 1].second,r2[i].second + l[i + 1].second });
	}
	cout << MAX << endl;
	return 0;
}

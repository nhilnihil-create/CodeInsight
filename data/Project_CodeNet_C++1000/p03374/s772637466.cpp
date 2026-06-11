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
pair<ll, lP>r[100002], l[100002], r2[100002], l2[100002];

int main(){
	cin >> N >> C;
	for (int i = 1; i != N + 1; ++i) {
		cin >> x[i] >> v[i];
	}
	x[N + 1] = C;
	for (int i = 1; i != N + 2; ++i) {
		r[i].first = r[i - 1].first + v[i] - x[i] + x[i - 1];
		r2[i].first = r2[i - 1].first + v[i] + (x[i - 1] - x[i]) * 2;
		if (r[i].first > r[i - 1].second.first)
			r[i].second = mkp(r[i].first, i);
		else
			r[i].second = r[i - 1].second;
		if (r2[i].first > r2[i - 1].second.first)
			r2[i].second = mkp(r2[i].first, i);
		else
			r2[i].second = r2[i - 1].second;
	}
	for (int i = N; i != -1; --i) {
		l[i].first = l[i + 1].first + v[i] - x[i + 1] + x[i];
		l2[i].first = l2[i + 1].first + v[i] + (x[i] - x[i + 1]) * 2;
		if (l[i].first > l[i + 1].second.first)
			l[i].second = mkp(l[i].first, i);
		else
			l[i].second = l[i + 1].second;
		if (l2[i].first > l2[i + 1].second.first)
			l2[i].second = mkp(l2[i].first, i);
		else
			l2[i].second = l2[i + 1].second;
	}
	for (int i = 0; i != N + 1; ++i) {
		MAX = max({ MAX,r[i].second.first + l2[i + 1].second.first,r2[i].second.first + l[i + 1].second.first });
	}
	cout << MAX << endl;
	return 0;
}
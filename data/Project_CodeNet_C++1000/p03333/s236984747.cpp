#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int N;
int l[100010], r[100010];

int main() {
	cin >> N;
	rep(i, N) {
		cin >> l[i] >> r[i];
	}
	++N;
	sort(l, l + N);
	sort(r, r + N);
	reverse(l, l + N);

	ll s = 0, ret;
	rep(i, N) {
		s += (l[i] - r[i]) * 2;
		ret = max(ret, s);
	}

	cout << ret << endl;
	return 0;
}
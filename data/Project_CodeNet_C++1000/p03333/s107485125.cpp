#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
typedef pair<P, P> PPP;

const ll MOD = 1e9 + 7;
const ll INF = 9e18;
const double DINF = 5e14;
const double eps = 1e-10;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second

int n;
vector<ll>l, r;
ll ans, lsum, rsum;

int main() {
	cin >> n;
	l.resize(n);
	r.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> l[i] >> r[i];
	}
	sort(ALLR(l));
	sort(ALL(r));
	for (int i = 0;i < n;i++) {//First left
		lsum += l[i];
		ans = max(ans, 2 * (lsum - rsum));
		rsum += r[i];
		ans = max(ans, 2 * (lsum - rsum));
	}
	lsum = 0, rsum = 0;
	for (int i = 0;i < n;i++) {//First right 
		rsum += r[i];
		ans = max(ans, 2 * (lsum - rsum));
		lsum += l[i];
		ans = max(ans, 2 * (lsum - rsum));
	}
	cout << ans << endl;
	return 0;
}
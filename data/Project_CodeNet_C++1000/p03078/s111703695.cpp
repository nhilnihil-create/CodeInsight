#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int x, y, z, k;
	cin >> x >> y >> z >> k;
	V<ll> a(x), b(y), c(z);
	rep(i, x)cin >> a[i];sort(all(a), greater<ll>());
	rep(i, y)cin >> b[i];sort(all(b), greater<ll>());
	rep(i, z)cin >> c[i];sort(all(c), greater<ll>());
	
	priority_queue<ll, V<ll>, less<ll>> pq;
	rep(i, x)rep(j, y)rep(l, z){
		if ((i + 1) * (j + 1) * (l + 1) > k)break;
		pq.push(a[i] + b[j] + c[l]);
	}
	
	rep(i, k) {
		cout << pq.top() << endl;
		pq.pop();
	}

}
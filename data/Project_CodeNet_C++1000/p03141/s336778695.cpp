#include<iostream>
#include<string>
#include <vector>
#include<queue>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<bitset>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define vsort(v) sort(v.begin(), v.end())
#define rv(v) reverse(v.begin(), v.end())
#define ll long long
#define PI 3.141592653589793
using vll = vector<ll>;
using Graph = vii;
const ll MOD = 998244353;

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	vll a(n), b(n), c(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
		ans -= b[i];
		c[i] = a[i] + b[i];
	}
	vsort(c);
	for (int i = 0; i < n; i += 2) {
		ans += c[n - 1 - i];
	}
	cout << ans << endl;
}
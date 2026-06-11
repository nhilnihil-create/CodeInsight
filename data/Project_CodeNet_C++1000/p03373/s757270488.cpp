#include<iostream>
#include<string>
#include <vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define vsort(v) sort(v.begin(), v.end())
#define rv(v) reverse(v.begin(), v.end())
#define ll long long
const ll MOD = 1e9 + 7;



int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int t = max(x, y);
	ll ans = 1e9 + 2;
	rep(i, 2*t + 1) {
		int v, w, cost;
		v = x - (i / 2);
		w = y - (i / 2);
		cost = max(0, v) * a + max(0, w) * b + i * c;
		ans = min((ll)cost, ans);
	}
	cout << ans << endl;
}
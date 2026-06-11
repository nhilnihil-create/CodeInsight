#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
	int n;
	cin >> n;
    ll ans = 0;
    vector<ll> dif(n);
    rep(i,n) {
        ll a, b;
        cin >> a >> b;
        dif[i] = a+b;
        ans -= b;
    }
    sort(dif.begin(), dif.end());
    reverse(dif.begin(), dif.end());
    rep(i,n) if(i%2==0) ans += dif[i];
	cout << ans << endl;
	return 0;
}

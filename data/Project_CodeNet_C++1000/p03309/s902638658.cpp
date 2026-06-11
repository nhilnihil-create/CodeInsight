#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=2e5+5;
int a[mxn];
ll dp[mxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i]-=i;
	}
	sort(a+1,a+n+1);
	int b;
	if(n%2)b=a[n/2+1];
	else b=(a[n/2]+a[n/2+1])/2;
	ll ans = 0LL;
	for(int i=1; i<=n; i++){
		ans += abs(a[i]-b);
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

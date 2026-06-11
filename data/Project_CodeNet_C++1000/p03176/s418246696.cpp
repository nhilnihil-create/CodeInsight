#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define all(a) (a).begin(),(a).end()
#define vll vector<ll>
#define fl(i,a,b) for(ll i=a;i<=b;i++)
#define flr(i,a,b) for(ll i=a;i>=b;i--)
#define print(v) for(auto x: v) {cout<<x<<" ";} cout<<"\n";
#define keep_unique(v) sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
#define test() ll te; cin >> te; while(te--)
#define MOD 998244353 //1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const int N=1e6;

ll n,ans;
vll h(N),a(N),dp(N);

ll t[2 * N];

void build() {
  for (ll i = n - 1; i > 0; --i) t[i] = max(t[i<<1] , t[i<<1|1]);
}

void modify(ll p, ll value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p] , t[p^1]);
}

ll query(ll l, ll r) {
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res =max(res, t[l++]);
    if (r&1) res =max(res, t[--r]);
  }
  return res;
}

int main()
{
	cin>>n;
	fl(i,0,n-1) cin>>h[i];
	fl(i,0,n-1) cin>>a[i];
	n++;
	build();
	fl(i,0,n-1)
	{
		ll ht=h[i];
		ll x=query(0,ht);
		dp[i]=x+a[i];
		modify(h[i],dp[i]);
		ans=max((ll)ans,dp[i]);
	}
	cout<<ans<<endl;
}
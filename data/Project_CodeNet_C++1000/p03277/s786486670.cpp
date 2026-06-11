#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define endl '\n'

ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
 
const ll N = (1e5) + 10;
const ll M = 320;
const ll Mod = 1e9 + 7;
ll ar[N],br[N];
vll u;

ll go(ll a, ll b){
	if(a == b) return 0;
	ll mid = (a+b)/2;
	ll ans = go(a,mid)+go(mid+1,b);
	u.clear();
	ll i,j;
	i = a; j = mid+1;
	while(i <= mid && j <= b){
		while(i<=mid && br[i] <= br[j]) u.pb(br[i++]), ans += j-(mid+1);
		if(i > mid) break;
		while(j<=b && br[j] < br[i]) u.pb(br[j++]);
	}
	while(i<=mid) u.pb(br[i++]), ans += j-(mid+1);
	while(j<=b) u.pb(br[j++]);
	for(i=a;i<=b;i++)
		br[i] = u[i-a];
	return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout<<setprecision(25);
    ll n,hi,lo,mid,a,b,c,d,i,j,k;
    cin>>n; vll v;
    for(i=1;i<=n;i++) cin>>ar[i], v.pb(ar[i]);
    ll amt = (n*(n+1))/2;
	ll inv,ans;
	sort(all(v)); v.resize(unique(all(v))-v.begin());
	lo = 0;
	hi = sz(v)-1;
    while(hi >= lo){
    	mid = (hi+lo)/2; ll aha = 0;
    	for(i=1;i<=n;i++) {br[i] = ((ar[i] >= v[mid]) ? 1 : -1), br[i] += br[i-1]; if(br[i] < 0) aha++;}
		inv = amt - go(1,n) - aha;
    	if(2*inv >= amt){
    		ans = mid;
    		lo = mid+1;
    	}
    	else{
    		hi = mid-1;
    	}
    }
    cout<<v[ans]<<endl;
    return 0;
}
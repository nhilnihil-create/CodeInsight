#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
const int MAXN = 2*1e5;
ll t[4*MAXN+1];
vector<ll>h,a;
void build(int v,int l,int r)
{
	if(l == r)t[v] = 0;
	else{
		int mid = (l+r)/2;
		build(2*v,l,mid);
		build(2*v+1,mid+1,r);
		t[v] = max(t[2*v],t[2*v+1]);
	}
}
void upd(int v,int tl,int tr,ll val,ll pos)
{
	if(tl == tr)t[v] = val;
	else{
		int tm = (tl+tr)/2;
		if(pos <= tm){
			upd(2*v,tl,tm,val,pos);
		}else{
			upd(2*v+1,tm+1,tr,val,pos);
		}
		t[v] = max(t[2*v],t[2*v+1]);
	}
}
ll get(int v,int l,int r,int tl,int tr)
{
	if(tl == l && tr == r)return t[v];
	if(l > r)return -INF;
	int tm = (tl+tr)/2;
	return max(get(2*v,l,min(r,tm),tl,tm),
	           get(2*v+1,max(l,tm+1),r,tm+1,tr));
}
int main()
{
   int n;
   cin>>n;
   a.resize(n);
   h.resize(n);
   for(ll&x:h)cin>>x;
   for(ll&x:a)cin>>x;
   for(int i=0;i<n;i++){
	   if(h[i] == 1){
		   upd(1,1,n,a[i],1);
		   continue;
	   }
	   else{
		ll r = get(1,1,h[i]-1,1,n);
		upd(1,1,n,r+a[i],h[i]);
	   }
   }
   cout<<t[1];
}

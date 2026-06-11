#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ve vector
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define sz(a) (int)(a.size())
//using namespace __gnu_pbds;
using namespace std;

// // // functions: find_by_order  & order_of_key
// typedef tree<
// int,
// null_type,
// less<int>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int inf=(int)2e9;
const long long mod=1000000007; //1E9+7
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

ll powmod(ll a,ll p){
	ll ans=1;
	while(p){
		if(p&1) ans*=a;
		p/=2;a*=a; ans%=mod;a%=mod;
	}
	return ans;
}
ll mdinv(ll a){return powmod(a,mod-2); }

struct dat{
	int w,s,v;
	dat(int ww,int ss,int vv){
		w=ww;s=ss;v=vv;	
	}
};

bool cmp(dat& a,dat& b){
	return a.w+a.s < b.w+b.s;
}

signed main(){
	IOS
	int n;cin>>n;
	ve<dat> v;
	forn(i,n){
		int w,s,x;cin>>w>>s>>x;
		v.pb(dat(w,s,x));
	}
	sort(all(v),cmp);
	int mm=2e4+2;
	vi DP(20004,0),DP_new(20004,0);
	for(int i=0;i<n;i++){
		for(int lim=0;lim<=mm;lim++){
			DP_new[lim]=DP[lim];
			int nwt=min(lim-v[i].w,v[i].s);
			if(nwt>=0)
				DP_new[lim]=max(DP_new[lim],v[i].v+DP[nwt]);
		}
		swap(DP_new,DP);
	}
	cout<<*max_element(all(DP));
}

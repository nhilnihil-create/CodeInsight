#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

const ll INF=1e18;

int n;
vector<iii> val;
ll memo[20005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	int a,b,c;
	rep(x,0,n){
		cin>>a>>b>>c;
		val.push_back(iii(ii(a,b),c));
	}
	
	sort(all(val),[](iii &i,iii &j){
		if (i.fi.fi+i.fi.se==j.fi.fi+j.fi.se) return i.fi.fi<j.fi.fi;
		else return i.fi.fi+i.fi.se<j.fi.fi+j.fi.se;
	});
	
	rep(x,1,20005) memo[x]=-INF;
	
	for (auto &it:val){
		//cout<<it.fi.fi<<" "<<it.fi.se<<" "<<it.se<<endl;
		
		rep(x,min(it.fi.se+1,20005-it.fi.fi),0){
			memo[x+it.fi.fi]=max(memo[x+it.fi.fi],memo[x]+it.se);
			//cout<<x+it.fi.fi<<" "<<memo[x]+it.se<<endl;
		}
	}
	
	ll ans=0;
	rep(x,0,20005) ans=max(ans,memo[x]);
	
	cout<<ans<<endl;
}

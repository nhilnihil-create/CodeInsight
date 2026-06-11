#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#include<string.h>
#define inf 9000000000000000000
#define maxn 200006
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
#define endl '\n'
#define mapint_iterator map<int,int> :: iterator
#define mapll_iterator map<ll,ll> :: iterator
#define setint_iterator set<int> :: iterator
#define setll_iterator set<ll> :: iterator
#define setpint_iterator set<pint> :: iterator
#define setpll_iterator set<pll> :: iterator
#define trace(x) cout<<#x<<": "<<x<<" "<<endl
#define trace2(x,y) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x,y,z) cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a,b,c,d) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define cout1(a) cout<<a<<endl
#define cout2(a,b) cout<<a<<' '<<b<<endl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<endl
typedef priority_queue<ll,vector<ll>,greater<ll> > pqset;
typedef priority_queue<pint,vector<pint>,greater<pint> > pqset_ll;
#define pb push_back
#define fi first
#define se second
#include<ext/pb_ds/assoc_container.hpp>
ll dxk[]={0,0,1,-1,1,1,-1,-1};
ll dyk[]={1,-1,0,0,1,-1,1,-1};
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> os_pair;
#define acc (ios::sync_with_stdio(false),cin.tie(0))
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(ll i=n;i>0;i--)
#define repeat(i,start,n) for(ll i=start;i<n;i++)
#define print(a,n) for(ll i=0;i<n;i++){ cout<<a[i]<<" ";}
ll ll_max(ll a,ll b,ll c){return max(a,max(b,c));}
int int_max(int a,int b,int c){return max(a,max(b,c));}
ll ll_min(ll a,ll b,ll c){return min(a,min(b,c));}
int int_min(int a,int b,int c){return min(a,min(b,c));}
ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);} 
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
ll power(ll a,ll b){
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	ll res=1;
	if(b%2){
		res=(c*c)%mod;
		res*=a;
		res%=mod;
	}
	else
		res=((c*c)%mod);
	return res;
}
//ifstream cin("b_read_on.txt"); ofstream cout("output3.txt");
//Chronology: Binary Search,Greedy,dp,dfs and similar
//Use (<<) for multiplication
//Use (>>) for division
// In dp, first try top-down,then bottom-up
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed;cerr.tie(NULL);
// find_by_order -> value at index
// order_of_key -> index of value
// while using (1<<i) use ((ll)1<<(ll)i) 
// if global declared initialise per testcase
int n;
ll v[1001],w[1001],s[1001];
ll dp[1001][20001];
ll func(int i,ll s1){
	if(i==n)
		return 0;
	if(dp[i][s1]!=-1)
		return dp[i][s1];
	ll ans=func(i+1,s1);
	if(w[i]<=s1)
		ans=max(ans,func(i+1,min(s[i],s1-w[i]))+v[i]);
	dp[i][s1]=ans;
	return ans;
}
void solve(int countu){
	cin>>n;
	vector<pair<pll,pll> > v1;
	rep(i,n){
		ll w,s,v;
		cin>>w>>s>>v;
		v1.pb({{w+s,s},{w,v}});
	}
	sort(v1.begin(),v1.end());
	reverse(v1.begin(),v1.end());
	rep(i,v1.size()){
		s[i]=v1[i].fi.se;
		v[i]=v1[i].se.se;
		w[i]=v1[i].se.fi;
	}
	memset(dp,-1,sizeof(dp));
	cout1(func(0,20000));
}
int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed;cerr.tie(NULL);cout.precision(10);
    int t=1;
	//scanf("%d",&t);
	int countu=1;
    while(t--){
    	solve(countu);
    	countu++;
    }
}



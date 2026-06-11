//order_of_key(k): Number of items strictly smaller than k .
//find_by_order(k): K-th element in a set (counting from zero).
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define full(x,n) x,x+n+1
#define full(x) x.begin(),x.end()
#define finish return 0

#define putb push_back
#define f first
#define s second

//logx(a^n)=loga(a^n)/logx(a)
//logx(a*b)=logx(a)+logx(b)
//logx(y)=log(y)/log(x)

#define ordered_set tree<ll,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define putf push_front
#define gainb pop_back

#define gainf pop_front
#define len(x) (ll)x.size()

// 1/b%mod=b^(m-2)%mod
// (a>>x)&1==0

typedef double db;
typedef long long ll;

const ll ary=2e5+5;
const ll mod=1e9+7;
const ll inf=1e18;

using namespace std;
using namespace __gnu_pbds;
ll n,mx,x,y,nv1,nv2;
vector<ll> g[ary],q;
void dfs(ll v,ll d=0,ll p=0){
	q.putb(v);
	if(d>mx){
		if(len(q)%2){
			nv1=nv2=q[len(q)/2];
		}
		else{
			nv1=q[len(q)/2-1];
			nv2=q[len(q)/2];
		}
		y=v;
		mx=d;
	}
	for(int i=0;i<len(g[v]);i++){
		ll to=g[v][i];
		if(to==p){
			continue;
		}
		dfs(to,d+1,v);
	}
	q.gainb();
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		ll a,b;
		cin>>a>>b;
		g[a].putb(b);
		g[b].putb(a);
	}
	dfs(1);
	mx=0;
	dfs(y);
	if(mx%3==1){
		cout<<"Second";
		return 0;
	}
	cout<<"First";
}
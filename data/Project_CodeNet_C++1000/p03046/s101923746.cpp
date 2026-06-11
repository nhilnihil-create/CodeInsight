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

const ll ary=1e5+5;
const ll mod=1e9+7;
const ll inf=1e18;

using namespace std;
using namespace __gnu_pbds;
ll m,k;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>m>>k;
	if(!k){
		for(int i=0;i<(1<<m);i++){
			cout<<i<<" "<<i<<" ";
		}
		return 0;
	}
	ll x=0;
	for(int i=0;i<(1<<m);i++){
		if(i==k){
			continue;
		}
		x=(x^i);
	}
	if(x!=k||k>=(1<<m)){
		cout<<-1;
		return 0;
	}
	vector<ll> q;
	for(int i=0;i<(1<<m);i++){
		if(i!=k){
			cout<<i<<" ";
			q.putb(i);
		}
	}
	cout<<k<<" ";
	for(int i=len(q)-1;i>=0;i--){
		cout<<q[i]<<" ";
	}
	cout<<k;
}
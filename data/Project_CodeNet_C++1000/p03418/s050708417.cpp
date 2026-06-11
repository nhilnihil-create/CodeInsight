#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
//#include<bits/extc++.h> inavilable in dev-cpp
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
#define me(i,k) memset(i,k,sizeof(i))
#define fr1(a,n) for(int a=1;a<=(n);a++)
#define frab(i,a,b) for(int i=(a);i<(b);i++)
#define fr0(i,n) for(int i=0;i<(n);i++)
#define trav(a,n) for(auto& a : n)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
const ll modn=1000000007;

int main(){
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	frab(x,k+1,n+1)
	{
		ll f=n/x;
		ll num=x-k;
		ans+=num*f;
		ll sur=n%x+1;
		ans+=max(sur-k,0LL);
	}
	if(k==0)ans=n*n;
	cout<<ans<<'\n';
	return 0;
}

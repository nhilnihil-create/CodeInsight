#include<bits/stdc++.h>
#include<string>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define N 300012
#define ll long long
#define ld long double
#define lli long long 
#define pb push_back
#define pf push_front
#define INF 1e18
// #define INF 10000000000
#define mod 1000000007
#define MOD 1000000007
#define mp make_pair
#define loop(n) for (lli i = 0; i < n; i++)
#define FOR(a,b) for (lli i = a; i < b; i+=1)
#define st(v) v.begin(),v.end()
#define F first
#define S second
#define mp make_pair
#define pii pair<lli,lli>
#define itr :: iterator it
#define w(t) cin>>t; while(t --)
#define inputarr(a,n) for(lli i=1;i<=n;i++)cin>>a[i];
#define input(a,n) for(lli i=0;i<n;i++){ lli x ; cin>>x; a.push_back(x);}
#define printarr(a,n) for(lli i=0;i<n;i++)cout<<a[i]; cout<<endl;
#define print(vec) for(auto xt : vec)cout<<xt; cout<<endl;
#define printset(st) for(auto xt : st) cout<<xt<<" ";    cout<<endl;
struct Edge;
typedef list<Edge>::iterator iter;
// const int N=(int)(1 * 1e5 + 10);
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// // typedef tree<int,null_type,less<int>,rb_tree_tag,
// // tree_order_statistics_node_update> indexed_set;
// typedef tree<int, null_type, less_equal<int>, 
//              rb_tree_tag, 
//              tree_order_statistics_node_update> 
//     ordered_set; 
std::vector<lli> v1;
std::vector<lli> dp(N,-1);
lli solve(lli k){

	if(dp[k]!=-1)return dp[k];

	if(k==0)return dp[k]=0;

	lli ans=0;
	for(auto x:v1){
		if(x>k)continue; 
		if(solve(k-x)==0 ){
			ans=1;
			break;
		}
	}
	return dp[k]=ans;
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	lli n,k;

	
	cin>>n>>k;
	// std::vector<lli> v1;
	input(v1,n);

	cout<<((solve(k))?"First":"Second");

}
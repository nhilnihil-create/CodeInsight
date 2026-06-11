#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int,int_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pair tree<pair<int,int>,int_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> pi; 
#define PI 3.1415926535897932384
#define FOR(i,vv,n) for(int i=vv;i<n;i++)
#define FORR(i,n,vv) for(int i=n-1;i>=vv;i--)
#define ve vector 
#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
#define minind(v) (min_element(v.begin(),v.end())-v.begin())
#define maxe(v) *max_element(v.begin(),v.end())
#define mine(v) *min_element(v.begin(),v.end())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define M 1000000007ll
#define M1 100000000000000000ll
#define PRECISE cout.precision(18);
#define BS(v,n) binary_search(v.begin(),v.end(),n)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.begin(),v.end(),greater <int>())
#define F first
#define S second
ve <string> v;

ll fun(string s){
	ll a=s.size();
	ll count=0;
	ll ans=0;
	FORR(i,a,0){
		if(s[i]=='A')
			ans+=count;
		else if(s[i]=='C'&&s[i-1]=='B')
			count++,i--;
	}
	return ans;
}

int main(){
	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
	//  #endif
    FAST
//	PRECISE

string s;
cin>>s;
string dummy;
ll n=s.size();
 FOR(i,0,s.size()){
 	if(s[i]=='A')
 		dummy.pb('A');
 	else if(s[i]=='B'&&i+1<=n-1&&s[i+1]=='C'){
 		dummy+="BC",i++;
 	}
 	else{
 		if(dummy.size()!=0){
 			v.pb(dummy);
 			dummy="";
 		}
 	}
 }
 		if(dummy.size()!=0)
 			v.pb(dummy);
 

 			ll ans=0;
 			for(auto i:v)
 				ans+=fun(i);
 			cout<<ans;



return 0;
 }
//  #pragma GCC optimize("Ofast")
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define rep(i, n) for(int i = 0; i < (n); ++i)
// #define all(x) (x).begin(),(x).end()
// #define ln '\n'
// constexpr long long MOD = 1000000007LL;
// //constexpr long long MOD = 998244353LL;
// typedef long long ll;
// typedef unsigned long long ull; 
// typedef pair<int, int> pii;
// typedef pair<long long, long long> pll;
// template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true;} return false; }
// template<class T, class U> inline bool chmin(T &a, U b) { if (a > b) { a = b; return true;} return false; }
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// gp_hash_table<int, int> dist[101010];

// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int N,M; cin >> N >> M;
//     vector<gp_hash_table<int, vector<int>>> G(N);
//     rep(i,M) {
//         int u,v,c; cin >> u >> v >> c;
//         --u; --v;
//         G[u][c].emplace_back(v);
//         G[v][c].emplace_back(u);
//     }

//     dist[0][0] = 0;
//     deque<pii> deq;
//     deq.emplace_back(0,0);
//     while (!deq.empty()) {
//         int v,c;
//         tie(v,c) = deq.front(); deq.pop_front();
//         if (c) {
//             for (auto nv : G[v][c]) {
//                 if (dist[nv].find(c)!=dist[nv].end() and dist[nv][c] <= dist[v][c]) continue;
//                 dist[nv][c] = dist[v][c];
//                 deq.emplace_front(nv,c);
//             }
//             if (dist[v].find(0)!=dist[v].end() and dist[v][0] <= dist[v][c]) continue;
//             dist[v][0] = dist[v][c];
//             deq.emplace_front(v,0);
//         } else {
//             for (auto i : G[v]) {
//                 if (dist[v].find(i.first)!=dist[v].end() and dist[v][i.first] <= dist[v][0] + 1) continue;
//                 dist[v][i.first] = dist[v][0] + 1;
//                 deq.emplace_back(v,i.first);
//             }
//         }
//     }

//     cout << (dist[N-1].find(0)!=dist[N-1].end() ? dist[N-1][0] : -1) << ln;
// }

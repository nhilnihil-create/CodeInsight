		#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;

 
const ll INF = 1e12;
const ll N =(100+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

int adj[N][N];
void solve(){
	int n;
	cin >> n;
	if(n%2==0){
		// int s = n+1;
		// vector<pll> cand;
		// set<int> vis;
		// for(int i =1;i <= n;i++){
		// 	for(int j = 1;j<=n;j++){
		// 		if(j != i and j+i == s and !vis.count(i) and !vis.count(j)){
		// 			cand.pb({i,j});
		// 			vis.in(i);
		// 			vis.in(j);
		// 		}
		// 	}
		// }
		// for(auto x:cand){
		// 	cout << x.f << " " << x.s << endl;
		// }
		int S = n+1;
		for(int i =1;i<=(n/2);i++){
			adj[i][n-i+1] = 1;
			adj[n-i+1][i] =1;
		}
		vector<pll> ed;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j<=n;j++){
				if(!adj[i][j]){
					ed.pb({i,j});
				}
			}
		}
		cout << ed.size() << endl;
		for(auto x:ed) 
			cout << x.f << " " << x.s << endl;
	}
	else{
		int k = (n-1)/2;
		for(int i = 1;i<=k;i++){
			adj[i][n-1-i+1] = 1;
			adj[n-1-i+1][i] = 1;
		}
		vector<pll> ed;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j<=n;j++){
				if(!adj[i][j]){
					ed.pb({i,j});
				}
			}
		}
		cout << ed.size() << endl;
		for(auto x:ed) 
			cout << x.f << " " << x.s << endl;
	}





}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen(".in","r",stdin);freopen(".out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
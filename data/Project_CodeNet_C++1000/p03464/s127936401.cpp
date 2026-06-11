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

 
const ll INF = 1e18;
const ll N =(1e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

int a[N];
void solve(){
	int n;
	cin >> n;
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}

	// for(int i =1;i<=20;i++){
	// 	int k = i;
	// 	int cur = k;
	// 	for(int j =1;j<=n;j++){
	// 		cur -= (cur % a[j]);
	// 	}
	// 	cout << cur << endl;
	// }
	int lo = 2,hi= 1e18;
	int ans = INF;
	for(;lo<=hi;){
		int k = (lo + hi)>>1ll;
		int cur = k;
		for(int i =1;i<=n;i++){
			cur -= (cur % a[i]);
		}
		if(cur == 2){
			ans = min(ans,k);
			hi = k-1;
		}
		else if(cur > 2) hi = k-1;
		else lo = k+1;
	}
	// cout << ans << endl;
	int x = ans;	
	lo = 2,hi = 1e18;
	ans = -1;
	for(;lo<=hi;){
		int k = (lo + hi)>>1ll;
		int cur = k;
		for(int i =1;i<=n;i++){
			cur -= (cur % a[i]);
		}
		if(cur == 2){
			ans = max(ans,k);
			lo = k+1;
		}
		else if(cur > 2) hi = k-1;
		else lo = k+1;
	}
	int y = ans;
	if(x == INF || y == -1){
		cout << -1 << endl;
		return;
	}
	cout << x << " " << y << endl;
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
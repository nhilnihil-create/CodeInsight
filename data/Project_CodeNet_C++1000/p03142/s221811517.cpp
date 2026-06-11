#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=1e5+500;

vector<ll> out[maxn];
vector<ll> in[maxn];
vector<ll> topol;
bool vis[maxn];
ll par[maxn];

void dfs(ll a){
	vis[a]=1;
	for(auto e:out[a]){
		if(!vis[e])dfs(e);
	}
	topol.pb(a);
}
ll koj[maxn];
void dfs_ans(ll a){
	vector<pii> vec;
	for(auto r:out[a]){
		vec.pb(mp(koj[r],r));
	}
	sort(vec.begin(),vec.end());
	vis[a]=1;
	for(auto e:vec){
		if(vis[e.S]==0){
			dfs_ans(e.S);
			par[e.S]=a;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n,m,rot;
	cin>>n>>m;
	for(ll i=0;i<m+n-1;i++){
		ll a,b;
		cin>>a>>b;
		out[a].pb(b);
		in[b].pb(a);
	}
	for(ll i=1;i<=n;i++){
		if(in[i].empty()){
			rot=i;
		}
	}
	dfs(rot);
	memset(vis,0,sizeof vis);
	reverse(topol.begin(),topol.end());
	for(ll i=0;i<n;i++){
		koj[topol[i]]=i;
	}			
	dfs_ans(rot);
	for(ll i=1;i<=n;i++){
		cout<<par[i]<<endl;
	}
}



















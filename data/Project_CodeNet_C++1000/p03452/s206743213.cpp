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

#define ll int
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=2e5+500;
const ll inf=1e9+900;
const ll maxCNT=maxn*30;


ll l[maxn];
ll r[maxn];
ll d[maxn];
vector<pii> ger[maxn];
ll minn[maxn];

void diks(ll a){
	queue<pii> qu;
	qu.push(mp(0,a));
	ll CNT=0;
	while(qu.size()){
		CNT++;
		if(CNT>maxCNT){
			cout<<"No";
			exit(0);
		}
		pii e=qu.front();
		qu.pop();
		ll v=e.S;
		ll w=e.F;
		if(minn[v]>w){
			minn[v]=w;
			for(auto e:ger[v]){
				if(minn[e.F]>e.S+minn[v]){
					qu.push(mp(e.S+minn[v],e.F));
				}
			}
		}
	}

}
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		cin>>l[i]>>r[i]>>d[i];
		ger[l[i]].pb(mp(r[i],d[i]));
		ger[r[i]].pb(mp(l[i],-d[i]));
	}
	fill(minn,minn+maxn,inf);
	for(ll i=1;i<=n;i++){
		if(minn[i]==inf){
			diks(i);
		}
	}
	for(ll i=0;i<m;i++){
		if(minn[r[i]]!=minn[l[i]]+d[i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}



















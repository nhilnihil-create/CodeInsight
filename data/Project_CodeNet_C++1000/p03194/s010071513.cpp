#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
#define INT_MAX 1<<30
const ll mod = 1e9+7;

map<ll,ll> prime_factor(ll n){
	map<ll,ll> mp;
	for(ll i=2; i*i<=n; i++){
		while(n % i == 0){
			mp[i]++;
			n /= i;
		}
	}
	if(n != 1) mp[n] = 1;
	return mp;
}

int main(){
	ll n,p; cin >> n >> p;
	auto mp = prime_factor(p);
	ll ans = 1;
	for(auto i : mp){
		ans *= pow(i.first,i.second/n);
	}
	cout << ans << endl;
}

#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(b-1);i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;
 
#define MOD 1000000007
#define INF 1000000007

int main(){
	string s;
	cin>>s;
	map<ll,ll> ma;
	ll now = 0;
	ma[now] = 0;
	rep(i,0,s.sz){
		ll a = s[i]-'a';
		ll old = now;
		now ^= (1LL<<a);
		if(ma.count(now)==0){
			ma[now] = INF;
		}
		ma[now] = min(ma[now],ma[old]+1);
		rep(j,0,26){
			ll bit = (1LL<<j);
			ll old1 = now^bit;
			if(ma.count(old1)==0){
				continue;
			}
			ma[now] = min(ma[now],ma[old1]+1);
		}
	}
	cout << max(1LL,ma[now]) << endl;
	return 0;
}
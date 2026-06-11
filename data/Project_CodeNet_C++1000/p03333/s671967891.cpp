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
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

ll calc(ll &now, ll l, ll r){
    ll res = 0;
    if(now < l){
        res += l - now;
        now = l;
    }else if(now > r){
        res += now - r;
        now = r;
    }
    return res;
}

int main(){
    ll n; cin >> n;
    multiset<P> lower, upper, lower2, upper2;
    rep(i,n){
        ll l,r; cin >> l >> r;
        lower.emplace(r,l);
        upper.emplace(-l,r);
        lower2.emplace(r,l);
        upper2.emplace(-l,r);
    }
    bool smaller = true;
    ll now = 0;
    ll ans = 0;
    while(!lower.empty()){
        if(smaller){
            ans += calc(now,(*lower.begin()).second,(*lower.begin()).first);
            auto itr = upper.find(P(-(*lower.begin()).second, (*lower.begin()).first));
            upper.erase(itr);
            lower.erase(lower.begin());
        }else{
            ans += calc(now,-(*upper.begin()).first,(*upper.begin()).second);
            auto itr = lower.find(P((*upper.begin()).second,-(*upper.begin()).first));
            lower.erase(itr);
            upper.erase(upper.begin());
        }
        smaller = !smaller;
    }
    ans += abs(now);
    ll ans2 = 0;
    now = 0;
    smaller = false;
    while(!lower2.empty()){
        if(smaller){
            ans2 += calc(now,(*lower2.begin()).second,(*lower2.begin()).first);
            auto itr = upper2.find(P(-(*lower2.begin()).second, (*lower2.begin()).first));
            upper2.erase(itr);
            lower2.erase(lower2.begin());
        }else{
            ans2 += calc(now,-(*upper2.begin()).first,(*upper2.begin()).second);
            auto itr = lower2.find(P((*upper2.begin()).second,-(*upper2.begin()).first));
            lower2.erase(itr);
            upper2.erase(upper2.begin());
        }
        smaller = !smaller;
    }
    ans2 += abs(now);
    cout << max(ans,ans2) << endl;
}
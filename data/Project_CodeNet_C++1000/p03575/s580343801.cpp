//#include<atcoder/all>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
//using namespace atcoder;

#define ll long long
#define pal pair<ll,ll>
#define pad pair<double,double>
#define PB push_back
#define MP make_pair
#define F first
#define S second

const ll MOD = 1e9+7;
const ll INF = 1e18;
const double EPS = 1e-8;

template<typename T,typename U>
bool chmax(T& max, const U& x){
	if(max<x){
		max = x;
		return true;
	}
	return false;
}

template<typename T,typename U>
bool chmin(T& min, const U& x){
	if(min>x){
		min = x;
		return true;
	}
	return false;
}


int main(){
	ll n,m;
    cin >> n >>m;
    ll ans=0;
    vector<vector<ll>> g(n+1);

    for(ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    while(true){
        bool f=true;
        for(ll i=1;i<=n;i++){
            if(g[i].size()==1){
                ll tmp=g[i][0];
                g[tmp].erase(remove(g[tmp].begin(),g[tmp].end(),i), g[tmp].end());
                g[i].erase(g[i].begin());
                ans++;
                f=false;
            }
        }
        if(f) break;
    }
    cout << ans << endl;
}
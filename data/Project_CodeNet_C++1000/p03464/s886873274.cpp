#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

int k;
vector<ll>a;

bool C(ll mid){
    rep(i,k){
        mid-=(mid)%a[i];
    }
    if(mid<=2)return true;
    else return false;
}

bool C2(ll mid){
    rep(i,k){
        mid-=(mid)%a[i];
    }
    if(mid>=2)return true;
    else return false;
}

void solve(){
    cin>>k;
    a.resize(k);
    ll maxV=0;
    rep(i,k){
        cin>>a[i];
        chmax(maxV,a[i]);
    }
    ll l=2,r=INF;
    while(r-l>1){
        ll mid=(l+r)/2;
        if(C(mid))l=mid;
        else r=mid;
    }
    ll maxv=l;
    l=1,r=2+k*maxV;
    while(r-l>1){
        ll mid=(l+r)/2;
        if(C2(mid))r=mid;
        else l=mid;
    }
    if(maxv>=r)cout<<r<<" "<<maxv<<"\n";
    else cout<<-1<<"\n";
}
 
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}

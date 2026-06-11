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

void solve(){
    int k;
    cin>>k;
    vector<ll>a(k);
    rep(i,k)cin>>a[i];
    a.pb(2);
    ll minv=2,maxv=2;
    for(int i=k-1;i>=0;--i){
        if((minv+a[i]-1)/a[i]*a[i]>maxv){
            cout<<-1<<"\n";
            return;
        }
        if(i<k-1){
        minv=(minv+a[i]-1)/a[i]*a[i];
        maxv=maxv/a[i]*a[i]+a[i]-1;
        }
        else {
            minv=2;maxv=3;
        }
    }
    cout<<minv<<" "<<maxv<<"\n";
}
 
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}

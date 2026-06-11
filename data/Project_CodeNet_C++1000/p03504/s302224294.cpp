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
    int n,c;
    cin>>n>>c;
    vector<pair<int,int>>v(c);
    rep(i,c)v[i].second=(i+1);
    vector<tuple<int,int,int>>g(n);
    rep(i,n)cin>>get<0>(g[i])>>get<1>(g[i])>>get<2>(g[i]);
    sort(g.begin(),g.end());
    rep(i,n){
        int s=get<0>(g[i]);
        int t=get<1>(g[i]);
        int C=get<2>(g[i]);
        rep(j,c){
            if(v[j].first==s&&v[j].second==C){
                v[j]={t,C};
                break;
            }
            else if(v[j].first<s){
                v[j]={t,C};
                break;
            }
        }
    }
    int cnt=0;
    rep(i,c){
        if(v[i].first)++cnt;
    }
    cout<<cnt<<"\n";
}
 
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}

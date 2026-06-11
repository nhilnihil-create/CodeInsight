#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
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
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    ll m,k;cin>>m>>k;
    ll mx=pow(2,m)-1;
    if(k>mx){
        cout<<-1<<endl;
        return 0;
    }
    if(k==0){
        vl z;
        rep(i,mx+1){
            z.push_back(i);
            z.push_back(i);
        }
        rep(i,(int)z.size()) cout<<z[i]<<" ";
        cout<<endl;
        return 0;
    }
    ll sum=0;
    rep(i,mx+1){
        if(i==k)continue;
        sum^=i;
    }
    if(sum!=k){
        cout<<-1<<endl;
        return 0;
    }
    vl ans;
    ans.push_back(k);
    rep(i,mx+1){
        if(i==k)continue;
        ans.push_back(i);
    }
    ans.push_back(k);
    drep(i,mx+1){
        if(i==k)continue;
        ans.push_back(i);
    }
    rep(i,(int)ans.size())cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
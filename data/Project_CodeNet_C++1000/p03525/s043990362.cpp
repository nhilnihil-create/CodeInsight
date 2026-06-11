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
int solve(int bit){
    int last=0;
    int res=INF;
    for(int i=0;i<24;i++){
        if((bit>>i)&1){
            int d=i-last;
            last=i;
            res=min(res,min(d,24-d));
        }
    }
    res=min(res,min(last,24-last));
    return res;
}
int main(){
    int n;cin>>n;
    vi d(n);rep(i,n) cin>>d[i];
    int mask=0;
    int tmp=0;
    vi num(13);
    rep(i,n) num[d[i]]++;
    for(int i=0;i<=12;i++){
        if(num[i]>=3||(i==12&&num[i]>=2)||(i==0&&num[i]>=1)){
            cout<<0<<endl;
            return 0;
        }
        if(num[i]==2){
            mask|=1<<i;
            mask|=1<<(24-i);
        }
        else if(num[i]==1){
            tmp|=1<<i;
        }
    }
    int ans=0;
    for(int b=0;b<(1<<13);b++){
        int m2=mask;
        for(int i=0;i<=12;i++){
            if(tmp&(1<<i)){
                if(b&(1<<i)) m2|=1<<(24-i);
                else m2|=1<<i;
            }
        }
        ans=max(ans,solve(m2));
    }
    cout<<ans<<endl;
    return 0;
}
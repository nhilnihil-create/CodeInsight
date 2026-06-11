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
ll n,k;
int main(){
    cin >> n >> k;
    vl a(n);
    rep(i,n) cin >> a[i];
    vl b;
    rep(i,n){
        ll sum=a[i];
        b.push_back(sum);
        for(int j=i+1;j<n;j++){
            sum+=a[j];
            b.push_back(sum);
        }
    }
    sort(b.rbegin(),b.rend());
    ll cur=0;
    for(int i=40;i>=0;i--){
        ll ncur=cur+(1ll<<i);
        int cnt=0;
        rep(i,(int)b.size()){
            if((ncur&b[i])==ncur) cnt++;
        }
        if(cnt>=k) cur=ncur;
    }
    cout << cur << endl;
    return 0;
}
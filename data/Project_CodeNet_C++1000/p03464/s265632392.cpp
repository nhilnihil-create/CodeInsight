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
int k;
vl a(110000);
ll s,e;
int main(){
    cin>>k;
    rep(i,k) cin>>a[i];
    s=2,e=2;
    int idx=k-1;
    bool ng=false;
    if(s%a[idx]!=0){
        cout<<-1<<endl;
        return 0;
    }
    else{
        while(1){
            e+=a[idx]-1;
            idx--;
            if(idx<0) break;
            ll cnt=e/a[idx]-s/a[idx];
            if(s%a[idx]==0){
                cnt++;
            }
            else s=(s/a[idx]+1)*a[idx];
            if(cnt==0){
                ng=true;
                break;
            }
            e=(e/a[idx])*a[idx];
        }
    }
    if(ng) cout<<-1<<endl;
    else cout<<s<<" "<<e<<endl;
    return 0;
}
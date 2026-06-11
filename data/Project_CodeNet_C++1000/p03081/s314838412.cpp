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
#define pb push_back
#define sz(x) (int)(x).size()
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
ll n,q;
string s;
char t[220000],d[220000];
int check(int c){
    rep(i,q){
        if(t[i]==s[c]){
            if(d[i]=='L')c--;
            else c++;
        }
        if(c<0)return 1;
        if(c>=n)return 2;
    }
    return 0;
}
int main(){
    cin>>n>>q;
    cin>>s;
    rep(i,q)cin>>t[i]>>d[i];
    int l=-1,r=n;
    while(r-l>1){
        int c=(l+r)/2;
        if(check(c)==1)l=c;
        else r=c;
    }
    int l2=-1,r2=n;
    while(r2-l2>1){
        int c=(l2+r2)/2;
        if(check(c)==2)r2=c;
        else l2=c;
    }
    int ans=n-(l+1)-(n-r2);
    cout<<ans<<endl;
    return 0;
}
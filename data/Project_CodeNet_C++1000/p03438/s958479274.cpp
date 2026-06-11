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
int n;
ll a[11000];
ll b[11000];
int main(){
    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    ll A=0,B=0;
    rep(i,n){
        ll need=b[i]-a[i];
        if(need>=0){
            need=(need+1)/2;
            A+=need;
            B+=(a[i]+need*2)-b[i];
        }
        else{
            B+=a[i]-b[i];
        }
    }
    //cout<<A<<" "<<B<<endl;
    if(A==B){
        cout<<"Yes"<<endl;
    }
    else{
        if(B>A){
            cout<<"No"<<endl;
        }
        else if(A>B){
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
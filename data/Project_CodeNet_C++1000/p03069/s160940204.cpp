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
    int n;cin >> n;
    string s;cin >> s;
    vi sumB(n+1),sumW(n+1);
    rep(i,n){
        if(s[i]=='#') sumB[i+1]=sumB[i]+1;
        else sumB[i+1]=sumB[i];
    }
    reverse(s.begin(),s.end());
    rep(i,n){
        if(s[i]=='.') sumW[i+1]=sumW[i]+1;
        else sumW[i+1]=sumW[i];
    }
    int ans=INF;
    for(int i=0;i<=n;i++){
        chmin(ans,sumB[i]+sumW[n-i]);
    }
    
    cout << ans << endl;
    
    return 0;
}
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
    int h,w,n;cin >> h >> w >> n;
    int sh,sw;cin >> sh >> sw;
    string s,t;cin >> s >> t;
    {
        //top
        int y=sh,x=sw;
        rep(i,n){
            if(s[i]=='U') y--;
            if(y<1){
                cout << "NO" << endl;
                return 0;
            }
            if(t[i]=='D') y++;
            if(y>h) y=h;
        }
    }
    {
        //bottom
        int y=sh,x=sw;
        rep(i,n){
            if(s[i]=='D') y++;
            if(y>h){
                cout << "NO" << endl;
                return 0;
            }
            if(t[i]=='U') y--;
            if(y<1) y=1;
        }
    }
    {
        //right
        int y=sh,x=sw;
        rep(i,n){
            if(s[i]=='R') x++;
            if(x>w){
                cout << "NO" << endl;
                return 0;
            }
            if(t[i]=='L') x--;
            if(x<1) x=1;
        }
    }
    {
        //left
        int y=sh,x=sw;
        rep(i,n){
            if(s[i]=='L') x--;
            if(x<1){
                cout << "NO" << endl;
                return 0;
            }
            if(t[i]=='R') x++;
            if(x>w) x=w;
        }
    }
    cout << "YES" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll mod = 1e9+7 ;
const ld error = 1e-9;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise - "<<__LINE__<<"\n"
#define tham getchar()
mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1e18+1;
const int nmax = 1e3+10;
///===========================================  template  =======================================================

int main(){
    FASTIO;

    map<char, int> dx, dy;
    dx['L'] = 0, dy['L'] = +1;
    dx['R'] = 0, dy['R'] = -1;
    dx['D'] = -1, dy['D'] = 0;
    dx['U'] = +1, dy['U'] = 0;

    int n, m, len;
    cin>>n>>m>>len;
    int x, y;
    cin>>x>>y;
    string s, t;
    cin>>s>>t;

    int lx = 1, rx = n;
    int ly = 1, ry = m;

    for(int i = len-1; i>=0; i--){
        lx = min(lx, lx+dx[t[i]]), rx = max(rx, rx+dx[t[i]]);
        ly = min(ly, ly+dy[t[i]]), ry = max(ry, ry+dy[t[i]]);

        lx = max(1, lx), rx = min(n, rx);
        ly = max(1, ly), ry = min(m, ry);

        lx = max(lx, lx+dx[s[i]]), rx = min(rx, rx+dx[s[i]]);
        ly = max(ly, ly+dy[s[i]]), ry = min(ry, ry+dy[s[i]]);
        if(lx > rx || ly > ry){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    if(lx <= x && x <= rx && ly <= y  && y <= ry) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

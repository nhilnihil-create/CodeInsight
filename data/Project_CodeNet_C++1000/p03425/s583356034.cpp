#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll m=0, a=0, r=0, c=0, h=0;
    rep(i, 0, n){
        string s;
        cin >> s;
        if(s[0]=='M')m++;
        if(s[0]=='A')a++;
        if(s[0]=='R')r++;
        if(s[0]=='C')c++;
        if(s[0]=='H')h++;
    }
    ll ans = m*a*r + m*a*c + m*a*h + m*r*c + m*r*h
    + m*c*h + a*r*c + a*r*h + a*c*h + r*c*h;
    cout << ans << endl;
}
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

bool dp[5000][16001];
bool dp2[5000][16001];

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin>>s; s.pb('T');
    int x,y; cin>>x>>y;
    int n = s.size();
    int f=0;
    rep(i,n){
        if (s[i]=='T') break;
        f++;
    }
    x-=f;
    s=s.substr(f+1); n=s.size();
    vi ax,ay;
    bool mode=false;
    int cnt=0;
    rep(i,n){
        if (s[i]=='F') cnt++;
        if (s[i]=='T'){
            if (cnt>0) (mode?ax:ay).pb(cnt);
            cnt=0;
            mode=!mode;
        }
    }
    if (cnt>0) (mode?ax:ay).pb(cnt);
    int m = ax.size();
    int l = ay.size();
    dp[0][8000]=true;
    rep(i,m)FOR(j,-8000,8000){
        if (j-ax[i]>=-8000 && dp[i][j+8000-ax[i]]) dp[i+1][j+8000]=true;
        if (j+ax[i]<=8000 && dp[i][j+8000+ax[i]]) dp[i+1][j+8000]=true;
    }
    dp2[0][8000]=true;
    rep(i,l)FOR(j,-8000,8000){
        if (j-ay[i]>=-8000 && dp2[i][j+8000-ay[i]]) dp2[i+1][j+8000]=true;
        if (j+ay[i]<=8000 && dp2[i][j+8000+ay[i]]) dp2[i+1][j+8000]=true;
    }
    if (dp[m][x+8000] && dp2[l][y+8000]){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}

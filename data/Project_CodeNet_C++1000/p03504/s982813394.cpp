#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
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

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,C; cin>>n>>C;
    vector<vi> sum(C,vi(100010));
    rep(i,n){
        int s,t,c; cin>>s>>t>>c; s--; t--; c--;
        sum[c][s]++; sum[c][t+1]--;
    }
    rep(i,C)rep(j,100000){
        sum[i][j+1] += sum[i][j];
    }
    rep(i,C)rep(j,100001){
        sum[i][j] = min(1,sum[i][j]);
    }
    int ans=0;
    rep(i,100000){
        int cnt=0;
        rep(c,C) cnt+=sum[c][i];
        chmax(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}

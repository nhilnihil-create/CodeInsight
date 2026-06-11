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
    ll n,k; cin>>n>>k;
    vi cnt(40);
    rep(i,n){
        ll a; cin>>a;
        rep(i,40)if(a>>(39-i)&1){
            cnt[i]++;
        }
    }
    vector<vll> dp(2,vll(41));
    rep(i,41) dp[1][i]=-1;
    dp[0][0] = 0;
    rep(i,40){
        int now = (k>>(39-i)&1);
        int c[2];
        c[1] = n-cnt[i];
        c[0] = cnt[i];
        rep(s,2)rep(j,2){
            int ns = s;
            if (dp[s][i]==-1) continue;
            if (now==0 && j==1 && s==0) continue;
            if (now==1 && j==0) ns = 1;
            chmax(dp[ns][i+1],dp[s][i]+(1ll<<(39-i))*c[j]);
        }
    }
    cout<<max(dp[0][40],dp[1][40])<<endl;
    return 0;
}

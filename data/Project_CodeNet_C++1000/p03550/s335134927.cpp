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

ll dp1[2020];
ll dp2[2020];

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Z,W; cin>>N>>Z>>W;
    vll a(N);
    rep(i,N) cin>>a[i];
    if (N==1){
        cout<<abs(W-a[0])<<"\n";
        return 0;
    }
    dp1[N-1] = dp2[N-1] = abs(a[N-1]-a[N-2]);
    RFOR(i,N-2,0){
        ll Y = (i>0)?a[i-1]:W;
        dp1[i] = abs(Y-a[N-1]);
        FOR(j,i+1,N-1) chmax(dp1[i],dp2[j]);

        ll X = (i>0)?a[i-1]:Z;
        dp2[i] = abs(X-a[N-1]);
        FOR(j,i+1,N-1) chmin(dp2[i],dp1[j]);
    }
    cout<<dp1[0]<<"\n";
    return 0;
}

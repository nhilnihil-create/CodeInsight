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
    int n; cin>>n;
    vi t(n),v(n);
    int T=0;
    rep(i,n){
        cin>>t[i];
        T += t[i];
    }
    vector<double> vmax(2*T+1, 1000);
    rep(i,n) cin>>v[i];
    int tmp=0;
    rep(i,n){
        rep(j,2*t[i]+1){
            chmin(vmax[2*tmp+j], (double)v[i]);
        }
        tmp+=t[i];
    }
    vmax.front() = 0.0;
    vmax.back() = 0.0;
    FOR(i,1,2*T) chmin(vmax[i], vmax[i-1]+0.5);
    RFOR(i,2*T-1,0) chmin(vmax[i], vmax[i+1]+0.5);
    // for(auto e:vmax){
    //     cout<<e<<" ";
    // }cout<<endl;
    double ans=0.0;
    FOR(i,1,2*T) ans+=(vmax[i-1]+vmax[i])*0.25;
    cout<<setp(12)<<ans<<"\n";
    return 0;
}

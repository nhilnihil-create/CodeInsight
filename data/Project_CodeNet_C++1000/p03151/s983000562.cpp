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

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vll a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    ll asum=0, bsum=0;
    rep(i,n) asum+=a[i];
    rep(i,n) bsum+=b[i];
    if (asum<bsum){
        cout<<"-1\n";
        return 0;
    }
    vll c;
    rep(i,n)if(a[i]>=b[i]) c.pb(a[i]-b[i]);
    sort(all(c));
    int m=c.size();
    int l=-1, r=n;
    while(r-l>1){
        int mid = (l+r)/2;
        if (mid<n-m){
            l=mid;
        }else{
            ll sum=asum-bsum;
            rep(i,n-mid) sum-=c[i];
            if (sum<0) l=mid;
            else r=mid;
        }
    }
    cout<<r<<"\n";
    return 0;
}

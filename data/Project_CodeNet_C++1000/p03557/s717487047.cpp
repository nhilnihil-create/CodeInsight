#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,double> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

ll a[100010],b[100010],c[100010];

ll cnt[100010];

int main() {
    int n;cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) cin>>c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    rep(i,n) {
        auto it = upper_bound(b,b+n,a[i]) - b;
        cnt[it]++;
    }
    rep(i,n) cnt[i+1] += cnt[i];
    ll ans = 0;
    rep(i,n) {
        auto it = upper_bound(c,c+n,b[i]) - c;
        ans += (n - it) * cnt[i];
    }
    cout<<ans<<endl;
}
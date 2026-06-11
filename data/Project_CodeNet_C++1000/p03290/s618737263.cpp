#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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

int main() {
    int d;cin>>d;
    ll g;cin>>g;
    int p[12];
    ll c[12];
    rep(i,d) cin>>p[i]>>c[i];
    ll ans=100000;
    for(int bit = 0;bit<(1<<d);bit++) {
        ll grad_s=0,prob_s=0;
        int last=-1;
        rep(j,d) {
            if((bit>>j)&1) {
                grad_s+=p[j]*(100*(j+1))+c[j];
                prob_s+=p[j];
            } else {
                last = j;
            }
        }
        if(grad_s >= g) {
            ans = min(ans,prob_s);
        } else {
            int need = ((g-grad_s-1)/(100*(last+1)))+1;
            if (need <= p[last]) {
                ans = min(ans,prob_s+need);
            }
        }
    }
    cout<<ans<<endl;
}
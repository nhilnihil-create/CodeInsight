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

ll a[200010],sum[200010];

int main() {
    int n;cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n) sum[i+1] = sum[i] + a[i];
    ll ans = 1LL<<60;
    rep(i,n+1) {
        int l = 0,r=i;
        while(r - l > 1) {
            int mid = (r+l)/2;
            if(sum[mid] >= sum[i] - sum[mid]) r = mid;
            else l = mid;
        }
        long long P = sum[l], Q = sum[i] - sum[l];
        long long P2 = sum[r], Q2 = sum[i] - sum[r];
        long long left_min = min(P, Q), left_max = max(P, Q);
        if (abs(P2-Q2) < abs(P-Q)) left_min = min(P2, Q2), left_max = max(P2, Q2);

        l = i, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (sum[mid] - sum[i] >= sum[n] - sum[mid]) r = mid;
            else l = mid;
        }
        long long R = sum[l] - sum[i], S = sum[n] - sum[l];
        long long R2 = sum[r] - sum[i], S2 = sum[n] - sum[r];
        long long right_min = min(R, S), right_max = max(R, S);
        if (abs(R2-S2) < abs(R-S)) right_min = min(R2, S2), right_max = max(R2, S2);

        ll tmp = max(left_max,right_max) - min(left_min,right_min);
        ans = min(ans,tmp);

    }

    cout<<ans<<endl;
}
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
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
    int N,M;cin>>N>>M;
    vector<ll> a(N);
    vector<P> bc(M);
    rep(i,N) cin>>a[i];
    sort(a.begin(),a.end());
    rep(i,M) {
        int b,c;cin>>b>>c;
        bc[i] = P(c,b);
    }
    sort(bc.begin(),bc.end());
    reverse(bc.begin(),bc.end());

    int now = 0;
    ll ans = 0;
    rep(i,M) {
        ll c = bc[i].first,b = bc[i].second;
        int plc = lower_bound(a.begin(),a.end(),c) - a.begin();
        if(plc - now <= b) {
            ans += c * (plc - now);
            for (int j = plc;j<N;j++) {
                ans += a[j];
            }
            cout<<ans<<endl;
            return 0;
        } else {
            ans += b * c;
            now += b;
        }
        // cout<<ans<<endl;
    }
    for (int j = now;j<N;j++) {
        ans += a[j];
    }
    cout<<ans<<endl;
}
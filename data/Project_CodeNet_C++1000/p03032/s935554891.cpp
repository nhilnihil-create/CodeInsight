#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
    int N,K;cin>>N>>K;
    vector<ll> v(N);
    rep(i,N) cin>>v[i];
    ll ans = 0;
    K = min(K,2*N);
    rep(i,K+1) {
        for (int j = (i+1)/2;j<min(i+1,N+1);j++) {
            for (int k = 0;k<j+1;k++) {
                priority_queue<int,vector<int>,greater<int>> qu;
                ll sum = 0;
                for (int p = 0;p<k;p++) {
                    sum+=v[p];
                    qu.push(v[p]);
                }
                for(int p = N - 1;p>N-1-j+k;p--) {
                    sum+=v[p];
                    qu.push(v[p]);
                }
                rep(p,i-j) {
                    sum -= qu.top();
                    qu.pop();
                }
                ans = max(ans,sum);
                // if(i==19) {
                //     cout<<k<<" "<<ans<<endl;
                // }
            }
        }
        // cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
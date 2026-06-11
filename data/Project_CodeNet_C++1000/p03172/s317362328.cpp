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
    vector<int> pre_vec(K+10,0);
    pre_vec[0] = 1;
    rep(i,N) {
        int a;cin>>a;
        vector<int> new_vec1(K+10,0),new_vec2(K+10,0);
        new_vec1[0] = pre_vec[0];
        rep(j,K) {
            new_vec1[j+1] = (new_vec1[j] + pre_vec[j+1])%MOD;
        }
        new_vec2 = new_vec1;
        rep(j,K-a+1) {
            new_vec2[j+a+1] = (new_vec2[j+a+1] - new_vec1[j] + MOD)%MOD;
        }
        pre_vec = new_vec2;
    }
    cout<<pre_vec[K]<<endl;
}
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

ll n;

void dfs(ll now,int bit,ll &counter) {
    if(now > n) return;
    if(bit == 7) counter++;
    dfs(now*10+3,bit|1,counter);
    dfs(now*10+5,bit|2,counter);
    dfs(now*10+7,bit|4,counter);
}

int main () {
    cin>>n;
    ll ans = 0;
    dfs(0,0,ans);
    cout<<ans<<endl;
}
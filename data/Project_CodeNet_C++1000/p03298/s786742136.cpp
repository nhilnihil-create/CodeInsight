#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<string,string> P;
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
    int n;cin>>n;
    string s;cin>>s;
    string front = s.substr(0,n),back = s.substr(n,n);
    reverse(back.begin(),back.end());
    map<P,ll> ma;
    for(int bit = 0;bit<(1<<n);bit++) {
        string a = "",b = "";
        rep(i,n) {
            if((bit>>i)&1) a += front[i];
            else b += front[i];
        }
        ma[P(a,b)]++;
    }

    ll ans=0;

    for(int bit = 0;bit<(1<<n);bit++) {
        string a = "",b = "";
        rep(i,n) {
            if((bit>>i)&1) a += back[i];
            else b += back[i];
        }
        ans += ma[P(b,a)];
    }

    cout<<ans<<endl;
}
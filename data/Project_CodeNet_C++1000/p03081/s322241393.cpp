#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define all(v) (v).begin(),v.end()
#define fi first
#define se second
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
using Pc=pair<char,char>;
int main() {
    int n,q; string s; cin >> n >> q >> s;
    vector<Pc> td(q);
    for (int i = 0; i < q; ++i) cin >> td[i].fi>>td[i].se;
    //左端
    int low = -1, high = n;
    while (high - low > 1) {
        int mid = (low + high)/2;
        bool check=false;
        int pos=mid;
         for (auto c : td) {
        if (s[pos] != c.fi) continue;
        if (c.se== 'L') --pos;
        else ++pos;
        if (pos < 0){check=true;break;}
    }
        if (check) low = mid;
        else high = mid;
    }
    int left_fall = high;

    // 右側の境目
    low = -1, high = n;
    while (high - low > 1) {
        bool check=false;
        int mid = (low + high) / 2;
        int pos=mid;
         for (auto c : td) {
        if (s[pos] != c.fi) continue;
        if (c.se == 'L') --pos;
        else ++pos;
        if (pos >=(int)s.size()){check=true;break;}
    }
        if (check) high = mid;
        else low = mid;
    }
    int right_fall = n-1-low;

    cout<< n - (left_fall + right_fall)<<endl;;
}
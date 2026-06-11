#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll>a(n), b(n), c(n);
    rep(i, 0, n)cin >> a[i] >> b[i] >> c[i];
    ll ans = -1;
    for(int bit=0; bit<(1<<3); bit++){
        vector<ll>tempa=a,tempb=b,tempc=c,sum(n);
        ll temp = 0;
        if(bit&(1<<0)){
            rep(i, 0, n)tempa[i]*=-1;
        }
        if(bit&(1<<1)){
            rep(i, 0, n)tempb[i]*=-1;
        }
        if(bit&(1<<2)){
            rep(i, 0, n)tempc[i]*=-1;
        }
        rep(i, 0, n)sum[i]=tempa[i]+tempb[i]+tempc[i];
        sort(sum.begin(),sum.end(),greater<ll>());
        rep(i, 0, m)temp += sum[i];
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
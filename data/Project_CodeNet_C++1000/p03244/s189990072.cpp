#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;
using str = string;

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

long int M = 1e+9+7;
int inf = 1e+9;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    int e5 = 100000;
    int n;
    cin >> n;
    int v;
    vi c0(e5+1),c1(e5+1);
    rep(i,n){
        cin >> v;
        if(i%2) c1[v]++;
        else c0[v]++;
    }

    int mxf0=0,mxs0=0,mxf1=0,mxs1=0;
    rep(i,e5+1){
        if(c0[mxf0] < c0[i]){
            mxs0=mxf0;
            mxf0=i;
        }else if(c0[mxs0] < c0[i]){
            mxs0=i;
        }
        if(c1[mxf1] < c1[i]){
            mxs1=mxf1;
            mxf1=i;
        }else if(c1[mxs1] < c1[i]){
            mxs1=i;
        }
    }
    
    int ans;

    if(mxf0 != mxf1) ans = n - (c0[mxf0]+c1[mxf1]);
    else ans = n - max(c0[mxf0]+c1[mxs1], c0[mxs0]+c1[mxf1]);
    cout << ans << endl;
    return 0;
}
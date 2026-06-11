#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cerr<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> inline bool chmax(t&a,u b){if(a<b){a=b;return true;}return false;}
template<class t,class u> inline bool chmin(t&a,u b){if(b<a){a=b;return true;}return false;}

int main(){
    int x,y,z,k;cin >> x >> y >> z >> k;
    vl a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    sort(a.begin(), a.begin() + x, greater<ll>());
    sort(b.begin(), b.begin() + y, greater<ll>());
    sort(c.begin(), c.begin() + z, greater<ll>());

    vl ans;
    rep(i,x){
        rep(j,y){
            rep(l,z){
                if((i+1)*(j+1)*(l+1) <= k) ans.emplace_back(a[i] + b[j] + c[l]);
                else break;
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    rep(i,k) cout << ans[i] << "\n";
}
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
const int INTMAX = 2147483647;
template<class t,class u> inline bool chmax(t&a,u b){if(a<b){a=b;return true;}return false;}
template<class t,class u> inline bool chmin(t&a,u b){if(b<a){a=b;return true;}return false;}

int main(){
    int n,m;cin >> n >> m;
    vector<P> p(m);
    rep(i,m) cin >> p[i].second >> p[i].first;

    sort(p.begin(), p.end());
    int ans = 1;
    int pretail = p[0].first;
    int prehead = p[0].second;
    for(int i=1;i<m;++i){
        if(p[i].second >= pretail){
            ++ans;
            pretail = p[i].first;
            prehead = p[i].second;
        }
    }
    cout << ans << endl;
}
#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll h,w,d,q;
vector<PLL> ck;
Vi l,r;
ll ma[90010];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>h>>w>>d;
    ll aa;
    ck.resize(h*w+1);
    rep(i,h)rep(j,w){
        cin>>aa;
        ck[aa]=(mp(j+1,i+1));
    }
    cin>>q;
    l.resize(q); r.resize(q);
    ll ans = 0;
    ll tmp = 0;
    rep(i,90010)ma[i] = 0;
    rep(i,d+1){
        if(i==0)continue;
        tmp = i;
        while(1){
            if(tmp+d>h*w)break;
            ma[tmp+d] += ma[tmp] + abs(ck[tmp].first - ck[tmp+d].first) + abs(ck[tmp].second - ck[tmp+d].second);
            tmp += d;
        }

    }
    rep(i,q){
        cin>>l[i]>>r[i];
        // while(1){
        //     if(l[i]==r[i])break;
        //     ans += abs(ck[l[i]].first - ck[l[i]+d].first);
        //     ans += abs(ck[l[i]].second - ck[l[i]+d].second);
        //     l[i] += d;
        // }
        ans = ma[r[i]] - ma[l[i]];
        print(ans);
        ans = 0;
    }
    return 0;
}

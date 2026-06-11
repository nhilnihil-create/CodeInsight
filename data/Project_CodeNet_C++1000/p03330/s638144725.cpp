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

ll n,c;
ll d[31][31];
ll cc[510][510];
vector<vi> v ;
ll cal(int id,ll color){
    ll ans = 0;
    rep(i,v[id].size()){
        ans += d[i+1][color] * v[id][i+1];
    }
    return ans;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>n>>c;
    v.resize(3);
    v[0].resize(c+1);
    v[1].resize(c+1);
    v[2].resize(c+1);
    rep(i,c)rep(j,c){
        cin>>d[i+1][j+1];
    }
    rep(j,n)rep(i,n){
        cin>>cc[i][j];
        v[(i+j+2)%3][cc[i][j]]++;
    }
    ll ans = INF;
    ll tmp;
    repi(i,1,c+1)repi(j,1,c+1)repi(k,1,c+1){
        if(i==j)continue;
        if(i==k)continue;
        if(j==k)continue;
        tmp = 0;
        tmp += cal(0,i);
        tmp += cal(1,j);
        tmp += cal(2,k);
        chmin(ans,tmp);
    }
    print(ans);
    return 0;
}
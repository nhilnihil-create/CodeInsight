#include <bits/stdc++.h>
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
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

void solve(){
    ll h,w;
    cin >> h >> w;
    matrix change(10,Vi(10));
    rp(i,10){
        rp(j,10){
            cin >> change[i][j];
        }
    }
    Vi val(10,INF);
    Vi v={0,1,2,3,4,5,6,7,8,9};
    do{
        ll start=v[0];
        if(start==1) continue;
        ll sum=0;
        ll pos=1;
        do{
            sum+=change[v[pos-1]][v[pos]];
            pos++;
        }while(v[pos-1]!=1);
        chmin(val[start],sum);
    }while(next_permutation(all(v)));
    val[1]=0;
    ll ans=0;
    rp(i,h){
        rp(j,w){
            ll a;
            cin >> a;
            if(a==-1) continue;
            ans+=val[a];
        }
    }
    print(ans);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}
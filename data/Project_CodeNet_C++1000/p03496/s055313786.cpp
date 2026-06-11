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
    ll n;
    cin >> n;
    Vi a(n);
    rp(i,n) cin >> a.at(i);
    ll mini=10000000,maxi=-100000000;
    ll minpos,maxpos;
    rp(i,n){
        if(chmax(maxi,a[i])) maxpos=i;
        if(chmin(mini,a[i])) minpos=i;
    }
    bool plus=true;
    if(mini<0&&maxi>0){
        if(abs(mini)<abs(maxi)){
            print(2*n-1);
            repi(i,1,n+1){
                princ(maxpos+1);
                print(i);
            }
        }else{
            print(2*n-1);
            repi(i,1,n+1){
                princ(minpos+1);
                print(i);
            }
            plus=false;
        }
    }else{
        print(n-1);
        if(mini<0) plus=false;
    }
    if(plus){
        rp(i,n-1){
            princ(i+1);
            print(i+2);
        }
    }else{
        rp(i,n-1){
            princ(n-i);
            print(n-i-1);
        }
    }


    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}
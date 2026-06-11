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
vi used(1000050,0);
void solve(){
    ll m,k;
    cin >> m >> k;
    vi bits;
    int dig=0;
    rp(i,31){
        if(k&(1<<i)) {
            bits.pb(1);
            dig=i+1;
        }
        else bits.pb(0);
    }
    if(m<dig){
        print(-1);
        return;
    }
    if(m==1&&k==0){
        print("0 0 1 1");
        return;
    }
    deque<ll> ans;
    ans.pb(k);
    if(__builtin_popcount(k)==1){
        if(k==1){
            if(m<=1){
                print(-1);
                return;
            }else{
                ans.pb(2);
                ans.pb(3);
                ans.push_front(2);
                ans.push_front(3);
                used[2]=used[3]=1;
            }
        }else{
            ans.pb(k+1);
            ans.pb(1);
            ans.push_front(k+1);
            ans.push_front(1);
            used[1]=used[k+1]=1;
        }
    }else{
        rp(i,31){
            if(bits[i]==1){
                ans.push_front(1ll<<i);
                ans.push_back(1ll<<i);
                used[1<<i]=1;
            }
        }
    }
    used[k]=1;
    rp(i,1ll<<m){
        if(used[i]==0){
            ans.push_front(i);
            ans.pb(i);
        }
    }
    ans.pb(k);
    for(auto an:ans){
        princ(an);
    }
    cout << endl;
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}
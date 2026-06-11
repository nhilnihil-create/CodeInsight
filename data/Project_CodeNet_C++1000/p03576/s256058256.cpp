#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os, const map<T,U>& mp){ os << "{"; for(auto& p : mp){ os << p << ","; } os << "}"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int,int>;
using vi = std::vector<int>;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

int N,K;

int main(){
    cin >> N >> K;
    vector<int> x(N),y(N);
    rep(i,N){
        cin >> x[i] >> y[i];
    }

    set<int> xs,ys;
    for(int i=0;i<N;i++){
        xs.insert(x[i]);
        ys.insert(y[i]);
    }

    map<ll,ll> mpx;
    map<ll,ll> rmpx;
    {
        int cnt = 0;
        for(auto v : xs){
            rmpx[cnt] = v;
            mpx[v] = cnt++;
        }
    }
    map<ll,ll> mpy;
    map<ll,ll> rmpy;
    {
        int cnt = 0;
        for(auto v : ys){
            rmpy[cnt] = v;
            mpy[v] = cnt++;
        }
    }

    rep(i,N){
        x[i] = mpx[x[i]];
        y[i] = mpy[y[i]];
    }

    int nx = mpx.size();
    int ny = mpy.size();

    /* cout << mpx << endl; */
    /* cout << mpy << endl; */

    /* cout << rmpx << endl; */
    /* cout << rmpy << endl; */

    /* cout << x << endl; */
    /* cout << y << endl; */

    ll ans = numeric_limits<long long>::max();
    rep(x1,nx){
        rep(y1,ny){
            for(int x2=x1;x2<nx;x2++){
                for(int y2=y1;y2<ny;y2++){
                    int cnt = 0;
                    rep(i,N){
                        if(x1<=x[i] && x[i]<=x2 && y1<=y[i] && y[i]<=y2){
                            cnt++;
                        }
                    }
                    if(cnt >= K){
                        ll dx = rmpx[x2] - rmpx[x1];
                        ll dy = rmpy[y2] - rmpy[y1];
                        chmin(ans, dx*dy);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

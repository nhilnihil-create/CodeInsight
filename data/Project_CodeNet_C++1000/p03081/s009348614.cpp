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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

int main(){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    vector<char> t(q),d(q);
    rep(i,q){
        cin >> t[i] >> d[i];
    }

    int ng,ok;
    ok= -1;
    ng = n;
    while(ng-ok>1){
        int m = (ok+ng)/2;
        bool flag = false;

        int now = m;
        for(int i=0;i<q;i++){
            if(s[now] == t[i]){
                if(d[i] == 'L'){
                    now--;
                }else{
                    now++;
                }
            }
            if(now < 0){
                flag = true;
                break;
            }
            else if(now >= n){
                break;
            }
        }

        if(flag){
            ok = m;
        }else{
            ng = m;
        }
    }

    int L = ok;

    ng = -1;
    ok = n;
    while(ok-ng>1){
        int m = (ng+ok)/2;

        bool flag = false;
        int now = m;
        for(int i=0;i<q;i++){
            if(t[i] == s[now]){
                if(d[i] == 'L'){
                    now--;
                }else{
                    now++;
                }
            }
            if(now < 0){
                break;
            }
            else if(now >= n){
                flag = true;
                break;
            }
        }

        if(flag){
            ok = m;
        }else{
            ng = m;
        }
    }

    int R = ok;

    int ans = L+1 + (n-R);
    cout << n - ans << endl;
}

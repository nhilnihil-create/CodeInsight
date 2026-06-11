#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define mp make_pair
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

bool check[500][100005];

int main(){
    int N; cin >> N;
    int k;
    for(int i=1;i<=N+10;i++){
        int t = i * (i-1) / 2;
        if(t > N){
            cout << "No" << endl;
            return 0;
        }
        if(t == N){
            k = i;
            break;
        }
    }

    int s = 0;
    for(int i=0;i<k;i++){
        const int len = k-1-i;
        for(int j=s;j<s+len;j++){
            //cout << i << " " << j << endl;
            check[i][j] = true;
        }

        for(int j=0;j<len;j++){
            check[i+1+j][s+j] = true;
        }
        s = s + len;
    }
    cout << "Yes" << endl;
    cout << k << endl;
    for(int i=0;i<k;i++){
        int cnt = 0;
        for(int j=0;j<N;j++) if(check[i][j]) cnt++;
        cout << cnt;
        for(int j=0;j<N;j++){
            if(check[i][j]) cout << " " << j+1;
        }
        cout << endl;
    }
}

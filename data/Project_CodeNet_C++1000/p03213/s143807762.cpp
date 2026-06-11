#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int N; cin >> N;
    VI prime(N+1, 1); prime[0] = 0; prime[1] = 0;
    for(int i=2; i<sqrt(N)+1; i++){
        if(prime[i] == 0) continue;
        for(int j=i+i; j<=N; j+=i) prime[j] = 0;
    }

    VI factor(N+1,0);
    REP(i,N){
        if(prime[i+1]==0) continue;
        int n = i+1;
        while(n <= N){
            factor[i+1] += N/n;
            n *= i+1;
        }
    }

    VI cand(5,0);
    REP(i,N){
        if(factor[i+1] >= 74) cand[0]++;
        if(factor[i+1] >= 24) cand[1]++;
        if(factor[i+1] >= 14) cand[2]++;
        if(factor[i+1] >= 4) cand[3]++;
        if(factor[i+1] >= 2) cand[4]++;
    }

    int ans = 0;
    ans += cand[0];
    ans += cand[1]*(cand[4]-1);
    ans += cand[2]*(cand[3]-1);
    ans += cand[3]*(cand[3]-1)/2*(cand[4]-2);
    cout << ans << endl;
    return 0;
}
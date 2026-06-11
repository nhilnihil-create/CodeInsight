#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
//template
template<class T> inline bool chmin(T &a, T b) {if (a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) {if (a < b){a = b; return true;} return false;}
//repetition
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
//container util
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//constant
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main() {
    int N; cin >> N;
    VL a(N); REP(i,N) cin >> a[i];
    VL dp(N); REP(i,N) dp[i] = INF;

    dp[0] = 0;

    FOR(i,1,N) {
        chmin(dp[i], dp[i-1] + abs(a[i] - a[i-1]));
        if (i != 1) chmin(dp[i], dp[i-2] + abs(a[i] - a[i-2]));
    }

    cout << dp[N-1] << endl;
}
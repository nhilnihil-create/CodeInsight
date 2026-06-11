#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

//typedef
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//conversion
inline LL toLong(string s) {LL v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) LL((a).size())
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define UNTIL(p) while(!(p))

//constant
const double EPS = 1e-5;
const double PI  = acos(-1.0);

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

#define PUTS(x) cout << (x) << endl;

const LL MOD = 1e9+7;
LL dp[3005][3005] = {0};
LL sum[3005][3005] = {0};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n;
    cin>>n;
    string s;
    cin>>s;

    dp[0][n] = 1;
    REP(i,n){
        dp[1][i] = 1;
        sum[1][i+1] += sum[1][i] + 1;
    }
    FOR(i,1,n){
        char c = s[i-1];
        REP(j,n){
            if(c == '<'){
                dp[i+1][j] = sum[i][n-i+1] - sum[i][j+1] + MOD;
            }
            else {
                dp[i+1][j] = sum[i][j+1] - sum[i][0] + MOD;
            }
            dp[i+1][j] %= MOD;
        }
        REP(j,n){
            sum[i+1][j+1] += sum[i+1][j] + dp[i+1][j];
            sum[i+1][j+1] %= MOD;
        }
    }

    PUTS(dp[n][0]);
}

#include <bits/stdc++.h> 
 
using namespace std;
 
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
 
//container util
//------------------------------------------
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
//constant
//--------------------------------------------
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 

const double EPS=0.00001;
const long double PI = acos(-1.0);
 
int dp[1<<26];
const int INF = 1e9;
 
int main() {
    string S;
    cin >> S;
    REP(i,(1<<26)) dp[i] = INF;
    dp[0] = 0;
    int stat = 0;
    REP(i,SZ(S)){
        stat ^= 1 << (S[i]-'a');
        REP(j,26) {
            int tmp = (stat^(1<<j));//今見ている文字がいない状態
            dp[stat] = min(dp[stat], dp[tmp]+1);
        }
    }
    cout<<max(dp[stat],1)<< endl;
    return 0;
}
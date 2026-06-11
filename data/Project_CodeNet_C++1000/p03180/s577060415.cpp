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

const LL NONE = -1000000000000ll;
const LL N = (1<<16);
LL n;
LL dp[N] = {0};
LL v[N] = {0};
LL a[16][16] = {0};

LL g(LL, LL, LL);
LL f(LL bit){
    if(dp[bit] != NONE)return dp[bit];
    LL score = v[bit];
    //REP(i,16){
    //    LL mask = 1<<i;
    //    if((bit & mask) != 0){
    //        // dp[bit - mask] + dp[mask] == dp[bit - mask] + 0
    //        score = max(score, f(bit - mask));
    //    }
    //}
    //return dp[bit] = score;
    return dp[bit] = max(score, g(bit, 0, 0));
}

LL g(LL bit, LL mask, LL dep){
    if(dep == n){
        if(mask == bit || mask == 0) return NONE;
        return f(bit - mask) + f(mask);
    }
    LL hot = (1 << dep);
    if((bit & hot) != 0){
        return max(g(bit, mask, dep + 1), g(bit, mask | hot, dep + 1));
    }
    else {
        return g(bit, mask, dep + 1);
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    REP(i,n)REP(j,n){
        cin>>a[i][j];
    }

    FOR(bit,3,1<<n){
        REP(i,n){
            if((bit & (1<<i)) != 0){
                REP(j,n){
                    if((bit & (1<<j)) != 0){
                        v[bit] += a[i][j];
                    }
                }
            }
        }
        v[bit] /= 2;
    }
    REP(i,N)dp[i] = NONE;
    REP(i,n)dp[1<<i] = 0;
    PUTS(f((1<<n) - 1));
}
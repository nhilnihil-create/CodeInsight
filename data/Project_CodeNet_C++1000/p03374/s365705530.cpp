#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = (s), i##_len=(n); i < i##_len; ++i)
#define FORS(i, s, n) for(int i = (s), i##_len=(n); i <= i##_len; ++i)
#define VFOR(i, s, n) for(int i = (s); i < (n); ++i)
#define VFORS(i, s, n) for(int i = (s); i <= (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FORS(i, 0, n)
#define VREP(i, n) VFOR(i, 0, n)
#define VREPS(i, n) VFORS(i, 0, n)
#define RFOR(i, s, n) for(int i = (s), i##_len=(n); i >= i##_len; --i)
#define RFORS(i, s, n) for(int i = (s), i##_len=(n); i > i##_len; --i)
#define RREP(i, n) RFOR(i, n, 0)
#define RREPS(i, n) RFORS(i, n, 0)
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<decltype(v[0])>())
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

using ll = long long;
using Pi_i = pair<int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VD = vector<double>;
using VI = vector<int>;
using VLL = vector<ll>;
using VS = vector<string>;
using VSH = vector<short>;

const int MOD = 1000000007;
const int INF = 1000000000;
const int NIL = -1;

template<class T, class S>
bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S>
bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}



int main(){
    int N; ll C;
    cin >> N >> C;
    VLL x(N+1), sumV(N+1);
    VLL maxInClockwise(N+1), maxInAntiClockwise(N+2);
    VI v(N+1);
    x[0] = sumV[0] = v[0] = 0;
    maxInClockwise[0] = 0;
    //O -> B -> O -> A
    FORS(i, 1, N){
        cin >> x[i] >> v[i];
        sumV[i] = sumV[i-1] + v[i];
        maxInClockwise[i] = max(maxInClockwise[i-1], sumV[i] - x[i]);
    }
    ll ans = maxInClockwise[N];
    RREPS(i, N){
        ll ret = sumV[N] - sumV[i-1] - C + x[i] + maxInClockwise[i-1];
        ret -=  C - x[i];
        chmax(ans, ret);
    }
    //O -> A -> O -> B
    maxInAntiClockwise[N+1] = 0;
    RREPS(i, N){
        maxInAntiClockwise[i] = max(maxInAntiClockwise[i+1], 
                                    sumV[N] - sumV[i-1] - C + x[i]);
    }
    REP(i, N){
        ll ret = sumV[i] - x[i] + maxInAntiClockwise[i+1];
        ret -= x[i];
        chmax(ans, ret);
    }

    cout << ans << endl;
    return 0;
}

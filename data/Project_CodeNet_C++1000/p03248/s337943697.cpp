#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>
#include <random>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

//struct edge {int from, to, cost;};

constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;
//inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}

template<class T> inline T sqr(T x) {return x*x;}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == '0' || s[n-1] == '1') {
        cout << -1 << endl;
        return;
    }
    REP(i,0,n/2) {
        if (s[i] != s[n-i-2]) {
            cout << -1 << endl;
            return;
        }
    }
    int prev = 1;
    REP(i,0,n-1) {
        cout << prev << " " << i + 2 << endl;
        if (s[i] == '1') {
            prev = i + 2;
        }
    }
}

int main() {
    solve();
    
    return 0;
}
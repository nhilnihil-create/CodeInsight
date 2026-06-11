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

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
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
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

//struct edge {int from, to, cost;};

constexpr double EPS = 1e-10;
constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;

template<class T> inline T sqr(T x) {return x*x;}

void solve() {
    int n;
    cin >> n;
    VI a(n);
    vector<double> b(n);
    REP(i,0,n) cin >> a[i];
    sort(all(a));
    int maxv = a[n-1];
    REP(i,0,n) {
        b[i] = 1.0 * maxv / 2 - a[i];
    }
    sort(all(b), [](auto &l, auto &r) {
        return abs(l) < abs(r);
    });
    cerr << b[0] << endl;
    cout << maxv << " " << int(1.0 * maxv / 2 - b[0]) << endl;
}

int main() {
    solve();
    
    return 0;
}

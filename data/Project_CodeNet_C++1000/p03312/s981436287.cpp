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

void solve() {
    int n;
    cin >> n;
    VLL a(n);
    REP(i,0,n) cin >> a[i];
    VLL ru(n+1);
    REP(i,0,n) ru[i+1] = ru[i] + a[i];
    LL ans = 1LL << 60;
    REP(i,1,n-2) {
        LL lsum = ru[i+1], rsum = ru[n] - ru[i+1];
        auto lit = lower_bound(all(ru), lsum/2);
        auto rit = lower_bound(all(ru), lsum + rsum / 2);
        int li = distance(ru.begin(), lit);
        int ri = distance(ru.begin(), rit);
        VVLL c(4);
        REP(j,0,2) {
            c[j*2].push_back(ru[li]);
            c[j*2].push_back(ru[i+1] - ru[li]);
            c[j].push_back(ru[ri] - ru[i+1]);
            c[j].push_back(ru[n] - ru[ri]);

            c[j*2+1].push_back(ru[li-1]);
            c[j*2+1].push_back(ru[i+1] - ru[li-1]);
            c[j+2].push_back(ru[ri-1] - ru[i+1]);
            c[j+2].push_back(ru[n] - ru[ri-1]);
        }
        REP(j,0,4) {
            LL diff = *max_element(all(c[j])) - *min_element(all(c[j]));
            ans = min(ans, diff);
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    
    return 0;
}
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

int n;
LL cost;

vector<LL> x;

LL ans;

LL f(LL qsize) {
    vector<LL> y = x;

    LL res = 0;

    queue<PLL> q;

    FORN(i, qsize) {
        auto e = y.back();
        y.pop_back();

        res += e + cost;

        q.push(MP(e, 1));
    }

    while (!y.empty()) {
        auto e = y.back();
        y.pop_back();

        auto f = q.front();
        q.pop();

        res += (f.FF - e) * (f.SS + 1) * (f.SS + 1) + cost;

        q.push(MP(e, f.SS + 1));
    }

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        res += f.FF * (f.SS + 1) * (f.SS + 1) + cost;
    }

    ans = min(ans, res);
    return res;
}

int main() {
    GI(n);
    GLL(cost);

    x.resize(n);

    FORN(i, n) {
        GLL(x[i]);
    }

    ans = 1LL * INF * INF;

    LL lo = 1;
    LL hi = n;
    
    while (lo < hi) {
        auto mid = (lo + hi) / 2;

        if (f(mid) < f(mid + 1)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forab(i, a, b) for(int i=(a);i<(b);++i)
#define foreach(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define sqr(x) ((x)*(x))
#define clr(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
#define all(a) (a).begin(),(a).end()
#define inf 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const double eps = 1e-8;
int dcmp(double x) { if (x < -eps) return -1; else return x > eps;}
#define se(x) cout<<#x<<" = "<<x<<endl

#ifdef CHEN_PC
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

const int N = 100010;
const int mod = 1000000007; // 10^9+7
int n;

int mark[N];

int solve() {
    clr(mark, 0);
    int v = 2;
    int s = 0;
    while (s < N) {
        s += v - 1;
        mark[s] = v;
        v++;
    }
//    forn (i, N) {
//        if (mark[i]) {
//            debug("%d %d\n", i, mark[i]);
//        }
//    }
    if (mark[n] == 0) {
        puts("No");
        return 0;
    }
    puts("Yes");
    int k = mark[n];
    vector<vi> ret(k, vi());
    int val = 1;
    forab (i, 1, k) {
        forn (j, i) {
            ret[j].push_back(val);
            ret[i].push_back(val);
            val++;
        }
    }

    printf("%d\n", k);
    for (auto arr : ret) {
        printf("%d", SZ(arr));
        for (auto u : arr) {
            printf(" %d", u);
        }
        puts("");
    }

    return 0;
}

int main(int argc, char *argv[]) {
#ifdef CHEN_PC
    freopen("D.in", "r", stdin);
#endif

    while (scanf("%d", &n) != EOF) {
        int ret = solve();
//        printf("%d\n", ret);
//        break;
    }
    return 0;
}


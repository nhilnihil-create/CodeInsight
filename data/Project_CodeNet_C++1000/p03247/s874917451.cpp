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
//    #define debug(...)
#else 
	#define debug(...)
#endif

const int N = 1010;
const int mod = 1000000007; // 10^9+7
int n;
int x[N], y[N];
int lis[32], ln;

int mod2(int val) {
    return ((val % 2) + 2) % 2;
}

string gao(int x, int y) {
    string ret;
    int xx = x;
    int yy = y;
    forn  (i, ln) {
        if (abs(xx) > abs(yy)) {
            if (xx > 0) {
                xx -= lis[i];
                ret += "R";
            } else {
                xx += lis[i];
                ret += "L";
            }
        }
        else {
            if (yy > 0) {
                yy -= lis[i];
                ret += "U";
            } else {
                yy += lis[i];
                ret += "D";
            }
        }
    }
    return ret;
}

void check(string s) {
    int x = 0;
    int y = 0;
    forn (i, SZ(s)) {
        if (s[i] == 'L') {
            x -= lis[i];
        }
        else if (s[i] == 'R') {
            x += lis[i];
        }
        else if (s[i] == 'U') {
            y += lis[i];
        }
        else if (s[i] == 'D') {
            y -= lis[i];
        }
    }
    debug("(%d, %d) ", x, y);
}

int solve() {
	int t = mod2(x[0] + y[0]);
	forn (i, n) {
		if (t != mod2(x[i] + y[i])) {
			printf("-1\n");
			return 0;
		}
	}
	ln = 31;
	int index = 0;
	ford (i, ln) {
	    lis[index++] = (1 << i);
	}
	lis[index] = 1;
    if (t == 1) {
        printf("%d\n", ln);
        forn (i, ln) {
            if (i) {
                printf(" ");
            }
            printf("%d", lis[i]);
        }
        puts("");
        forn (i, n) {
            string ret = gao(x[i], y[i]);
            check(ret);
            puts(ret.c_str());
        }
    }
    else {
        printf("%d\n", ln+1);
        forn (i, ln+1) {
            if (i) {
                printf(" ");
            }
            printf("%d", lis[i]);
        }
        puts("");
        forn (i, n) {
            string ret = gao(x[i], y[i]+1);
            ret += "D";
            check(ret);
            puts(ret.c_str());
        }
    }
	return 0;
}

int main(int argc, char *argv[]) {
#ifdef CHEN_PC
	freopen("D.in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF) {
		forn (i, n) {
			scanf("%d %d", x + i, y + i);
		}
		int ret = solve();
		// printf("%d\n", ret);
	}
	return 0;
}


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
map<int, int> dic;
int lis[32];

int mod2(int val) {
    return ((val % 2) + 2) % 2;
}

int flag(int x) {
    return x > 0 ? 1 : -1;
}

pair<vi, vi> gao(int x, int y) {
    int dp[32][4];
    pair<vi, vi> ans[32][4];
    clr(dp, 0);
    dp[31][0] = 1;
    ford (i, 31) forn (s, 4) {
        int val = 1 << i;
        if (dp[i + 1][s] == 0) continue;
//        debug("dp[%d][%d] = %d\n", i + 1, s, dp[i + 1][s]);
        if (x & val) {
            if (y & val) {
                if (s == 0) {
                    continue;
                }
                else if (s == 1) {
                    dp[i][1] = 1;
                    ans[i][1] = ans[i + 1][s];
                    ans[i][1].second.push_back(val);
                }
                else if (s == 2) {
                    dp[i][2] = 1;
                    ans[i][2] = ans[i + 1][s];
                    ans[i][2].first.push_back(val);
                }
                else if (s == 3) {
                    dp[i][2] = 1;
                    ans[i][2] = ans[i + 1][s];
                    ans[i][2].first.push_back(-val);

                    dp[i][1] = 1;
                    ans[i][1] = ans[i + 1][s];
                    ans[i][1].second.push_back(-val);
                }
            }
            else {
                if (s == 0) {
                    dp[i][0] = 1;
                    ans[i][0] = ans[i + 1][s];
                    ans[i][0].first.push_back(val);
                }
                else if (s == 1) {
                    dp[i][0] = 1;
                    ans[i][0] = ans[i + 1][s];
                    ans[i][0].first.push_back(-val);

                    dp[i][3] = 1;
                    ans[i][3] = ans[i + 1][s];
                    ans[i][3].second.push_back(val);
                }
                else if (s == 2) {
                    continue;
                }
                else if (s == 3) {
                    dp[i][3] = 1;
                    ans[i][3] = ans[i + 1][s];
                    ans[i][3].second.push_back(-val);
                }
            }
        }
        else {
            if (y & val) {
                if (s == 0) {
                    dp[i][0] = 1;
                    ans[i][0] = ans[i + 1][s];
                    ans[i][0].second.push_back(val);
                }
                else if (s == 1) {
                    continue;
                }
                else if (s == 2) {
                    dp[i][3] = 1;
                    ans[i][3] = ans[i + 1][s];
                    ans[i][3].first.push_back(val);

                    dp[i][0] = 1;
                    ans[i][0] = ans[i + 1][s];
                    ans[i][0].second.push_back(-val);
                }
                else if (s == 3) {
                    dp[i][3] = 1;
                    ans[i][3] = ans[i + 1][s];
                    ans[i][3].first.push_back(-val);
                }
            }
            else {
                if (s == 0) {
                    dp[i][1] = 1;
                    ans[i][1] = ans[i + 1][s];
                    ans[i][1].first.push_back(val);

                    dp[i][2] = 1;
                    ans[i][2] = ans[i + 1][s];
                    ans[i][2].second.push_back(val);
                }
                else if (s == 1) {
                    dp[i][1] = 1;
                    ans[i][1] = ans[i + 1][s];
                    ans[i][1].first.push_back(-val);
                }
                else if (s == 2) {
                    dp[i][2] = 1;
                    ans[i][2] = ans[i + 1][s];
                    ans[i][2].second.push_back(-val);
                }
                else if (s == 3) {
                    continue;
                }
            }
        }
    }
    return ans[0][0];
}

string handle(int x, int y) {

    int fx = flag(x);
    int fy = flag(y);
    pair<vi, vi> ret = gao(x * fx, y * fy);

//    int sum = 0;
//    for (auto val : ret.first) {
//        sum += val;
//        debug(" %d,", val);
//    }
//    debug(" x=%d\n", sum);
//    sum = 0;
//    for (auto val : ret.second) {
//        sum += val;
//        debug(" %d,", val);
//    }
//    debug(" y=%d\n\n", sum);

    string str(31, '0');
    for (auto v : ret.first) {
        if (v > 0) {
            str[ dic[v] ] = (fx > 0 ? 'R' : 'L');
        }
        else {
            str[ dic[-v] ] = (fx > 0 ? 'L' : 'R');;
        }
    }
    for (auto v : ret.second) {
        if (v > 0) {
            str[ dic[v] ] = (fy > 0 ? 'U' : 'D');
        }
        else {
            str[ dic[-v] ] = (fy > 0 ? 'D' : 'U');
        }
    }

    return str;
}

int solve() {
	int t = mod2(x[0] + y[0]);
	forn (i, n) {
		if (t != mod2(x[i] + y[i])) {
			printf("-1\n");
			return 0;
		}
	}
    int index = 0;
    ford (i, 31) {
        lis[index] = (1 << i);
        dic[1 << i] = index++;
    }
	if (t == 1) {
	    puts("31");
	    ford (i, 31) {
	        printf("%d", (1<<i));
	        if (i != 0) {
	            printf(" ");
	        }
	    }
        puts("");
        forn (i, n) {
            string str = handle(x[i], y[i]);
            int xx = 0;
            int yy = 0;
            forn (i, SZ(str)) {
                if (str[i] == 'L') {
                    xx -= lis[i];
                }
                else if (str[i] == 'R') {
                    xx += lis[i];
                }
                else if (str[i] == 'U') {
                    yy += lis[i];
                }
                else if (str[i] == 'D') {
                    yy -= lis[i];
                }
            }
            debug("(%d,%d) ", xx, yy);
            printf("%s\n", str.c_str());
        }
	}
	else {
	    lis[31] = 1;
        puts("32");
        ford (i, 31) {
            printf("%d ", (1<<i));
        }
        puts("1");
        forn (i, n) {
            string str = handle(x[i] + 1, y[i]);
            str += "L";
            int xx = 0;
            int yy = 0;
            forn (i, SZ(str)) {
                if (str[i] == 'L') {
                    xx -= lis[i];
                }
                else if (str[i] == 'R') {
                    xx += lis[i];
                }
                else if (str[i] == 'U') {
                    yy += lis[i];
                }
                else if (str[i] == 'D') {
                    yy -= lis[i];
                }
            }
            debug("(%d,%d) ", xx, yy);
            printf("%s\n", str.c_str());
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


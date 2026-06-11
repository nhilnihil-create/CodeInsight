#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

int N;
vector< pair<int, int> > can;   // first: N second: 幅

signed main()
{
    cin >> N;

    if(N == 1) {
        printf("Yes\n");
        printf("2\n");
        printf("1 1\n");
        printf("1 1\n");
        return 0;
    }

    // 構築可能な N か確認
    int tmp_n = 1;
    int width = 2;
    bool able = false;
    while(tmp_n <= N) {
        if(tmp_n == N) {
            able = true;
            break;
        }
        tmp_n += width;
        width++;
    }
    if(!able) {
        printf("No\n");
        return 0;
    }
    width--;

    printf("Yes\n");
    vector< vector<int> > ans(width+1, vector<int>(width, 0));
    int unused = 1;
    for(int i = 0; i <= width; ++i) {
        // 自分より前の値を一つずつ入れる
        for(int j = 0; j < i; ++j) {
            ans[i][j] = ans[j][i-1];
        }
        // まだ使っていない値を入れる
        for(int j = i; j < width; ++j) {
            ans[i][j] = unused;
            unused++;
        }
    }

    // 答えの表示
    printf("%zu\n", ans.size());
    REP(i, ans.size()) {
        printf("%lld ", width);
        REP(j, ans[i].size()) {
            printf("%lld", ans[i][j]);
            if(j != ans[i].size()-1) { printf(" "); }
            else { printf("\n"); }
        }
    }

    return 0;
}

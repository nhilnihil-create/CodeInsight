#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define FOR(i, start, end) for(ll i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    vector<vector<int>> P(N, vector<int>(11));
    REP (i, N) {
        REP (j, 10) {
            cin >> F[i][j];
        }
    }
    REP (i, N) {
        REP (j, 11) {
            cin >> P[i][j];
        }
    }

    int ans = INT_MIN;
    FOR (bit, 1, 1 << 10) {
        int profit = 0;
        REP (i, N) {
            int cnt = 0;
            REP (j, 10) {
                int open = (bit >> j) & 1;
                if (open == 1 && F[i][j] == 1) {
                    cnt++;
                }
            }
            profit += P[i][cnt];
        }
        ans = max(ans, profit);
    }
    cout << ans << endl;

    return 0;
}
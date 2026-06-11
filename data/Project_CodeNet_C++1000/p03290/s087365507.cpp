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
    int D, G;
    cin >> D >> G;
    vector<int> P(D);
    vector<int> C(D);
    REP (i, D) {
        cin >> P[i] >> C[i];
    }

    int ans = INT_MAX;
    REP (bit, 1 << D) {
        int point = 0;
        int count = 0;
        int s = -1;

        REP (i, D) {
            int b = (bit >> i) & 1;
            if (b == 0) {
                s = i;
            } else {
                point += P[i] * 100 * (i + 1) + C[i];
                count += P[i];
            }
        }
        if (point >= G) {
            ans = min(ans, count);
            continue;
        }
        if (s == -1) {
            continue;
        }

        REP (i, P[s]) {
            point += (s + 1) * 100;
            count++;
            if (point >= G) {
                ans = min(ans, count);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
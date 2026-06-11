#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = INT_MAX / 2;

vector<int> problems;
vector<int> bonus;

// based on editorial.pdf
int main(void) {
    int D;
    ll G;
    cin >> D >> G;

    problems.resize(D);
    bonus.resize(D);
    for (int i = 0; i < D; i++) {
        int p, c;
        cin >> p >> c;
        problems[i] = p;
        bonus[i] = c;
    }

    int ans = INF;

    // bits means all problems having (i+1) * 100 points will be solved
    // e.g. 001 means only problems having 100.
    for (int bits = 0; bits < (1 << D); bits++) {
        set<int> for_bonus;
        for (int i = 0; i < D; i++) {
            if ((bits >> i) & 1) {
                for_bonus.insert(i);
            }
        }

        int point = 0;
        int num = 0;

        // printf("bonus: ");
        for (auto pb : for_bonus) {
            // printf("%d ", pb);
            num += problems[pb];
            point += problems[pb] * (pb + 1) * 100 + bonus[pb];
        }
        // printf("\n");
        // printf("after bonus. num: %d, point: %d\n", num, point);

        if (point >= G) goto end;

        for (int i = D - 1; i >= 0; i--) {
            if (for_bonus.find(i) != for_bonus.end()) continue;
            for (int j = 0; j < problems[i] - 1; j++) {
                num++;
                point += 100 * (i + 1);
                // printf("[%d] num: %d, point: %d\n", i, num, point);
                if (point >= G) goto end;
            }
        }

end:
        if (point >= G) {
            chmin(ans, num);
        }
    }

    cout << ans << endl;

    return 0;
}

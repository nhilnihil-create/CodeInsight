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

vector<int> vs;

// 21:38
int main(void) {
    int N, K;
    cin >> N >> K;

    vs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vs[i];
    }

    int ans = -INF;

    // get n jewel
    for (int n = min(N, K); n >= 0; n--) {
        // nl is jewels from left
        // nr is jewels from right
        for (int nl = n; nl >= 0; nl--) {
            int nr = n - nl;

            priority_queue<int, vector<int>, greater<int>> q;
            for (int i = 0; i < nl; i++) {
                q.push(vs[i]);
            }
            for (int i = 0; i < nr; i++) {
                q.push(vs[N - 1 - i]);
            }

            for (int i = 0; i < K - n && !q.empty(); i++) {
                const int v = q.top();
                if (v >= 0) {
                    break;
                }
                q.pop();
            }

            int cand = 0;
            while (!q.empty()) {
                const int v = q.top();
                // printf("v: %d\n", v);
                q.pop();
                cand += v;
            }
            // printf("cand: %d\n", cand);
            chmax(ans, cand);
        }
    }

    cout << ans << endl;

    return 0;
}

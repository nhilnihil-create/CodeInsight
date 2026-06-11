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

vector<int> as;

ll solve(const int N) {
    ll ans = 0;

    // [begin, end)
    int begin = 0;
    int end = 0;
    int acc = 0;

    while (begin < N) {
        end = max(begin, end);

        while (true) {
            if (end < N && (acc + as[end]) == (acc ^ as[end])) {
                acc ^= as[end];
                end++;
                // printf("%d\n", acc);
            } else {
                break;
            }
        }

        ans += end - begin;
        // printf("2. begin: %d, end: %d, acc: %d, ans: %lld\n", begin, end, acc, ans);

        acc ^= as[begin];
        begin++;
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    cout << solve(N) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <queue>

using namespace std;

bool isPrime(long N) {
    if (N <= 1) {
        return false;
    }

    for (long i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

// vector<int> s = cumulativeSum(vs,N);
// [left, right) => s[right] - s[left]
vector<int> cumulativeSum(vector<int> vs, int N) {
    vector<int> rs(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        rs[i + 1] = rs[i] + vs[i];
    }
    return rs;
}

int main() {


    int Q;
    cin >> Q;

    vector<int> V;
    int m = 100000;
    for (int i = 0; i <= m; ++i) {
        if (i % 2 == 0) {
            V.push_back(0);
            continue;
        }
        if (isPrime(i) && isPrime((i + 1) / 2)) {
            V.push_back(1);
        } else {
            V.push_back(0);
        }
    }

    vector<int> ys = cumulativeSum(V,m);

    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;

        // [l,r] = [l,r+1)

        cout << ys[r + 1] - ys[l] << endl;

    }


    return 0;
}
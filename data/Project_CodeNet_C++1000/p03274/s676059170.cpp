#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> x(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    int output = 1e9;
    for (int i = 0; i < N - K + 1; i++) {
        int tmp;
        if (x[i] >= 0) {
            tmp = x[i + K - 1];
        } else if (x[i] < 0) {
            if (x[i + K - 1] > 0) {
                tmp = min(-x[i] * 2 + x[i + K - 1], -x[i] + x[i + K - 1] * 2);
            } else if (i == N - K) {
                tmp = -x[i] + x[i + K];
            } else {
                tmp = 1e9;
            }
        }
        if (tmp < output) {
            output = tmp;
        }
    }

    cout << output << endl;

    return 0;
}

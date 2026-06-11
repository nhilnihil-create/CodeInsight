#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    int cnt = 0;
    for (int i = min(A, B); i >= 1; i--) {
        if ((A % i == 0) && (B % i == 0)) {
            cnt++;
            if (cnt == K ) {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}

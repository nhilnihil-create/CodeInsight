#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    int N;
    cin >> N;

    string A, B, C;
    cin >> A >> B >> C;

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        unordered_set<char> s;
        s.insert(A[i]);
        s.insert(B[i]);
        s.insert(C[i]);

        if (s.size() == 3) {
            ans += 2;
        } else if (s.size() == 2) {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}
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
    int A, B;
    cin >> A >> B;

    string S;
    cin >> S;

    if (S[A] != '-') {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < S.size(); ++i) {
        if (i == A) {
            continue;
        }

        int x = S[i] - '0';
        if (x < 0 || 9 < x) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}

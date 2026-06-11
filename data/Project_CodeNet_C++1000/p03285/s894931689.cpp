#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool Solve(int N) {
        for (int i = 0; i <= 100 / 7; i++) {
            for (int j = 0; j < 100 / 4; j++) {
                if (7 * i + 4 * j == N)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    if (s.Solve(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

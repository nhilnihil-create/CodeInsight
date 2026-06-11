#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int maxCount = 0;
    rep(i, N) {  // pos
        int count = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            bool left = false, right = false;
            for (int j = 0; j < i; j++) {
                if (S.at(j) == c) left = true;
            }
            for (int j = i; j < N; j++) {
                if (S.at(j) == c) right = true;
            }
            if (left && right) count++;
        }
        maxCount = max(maxCount, count);
    }

    cout << maxCount << endl;

    return 0;
}

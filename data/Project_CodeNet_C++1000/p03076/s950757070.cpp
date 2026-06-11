#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    vector<int> X(5);
    cin >> X.at(0) >> X.at(1) >> X.at(2) >> X.at(3) >> X.at(4);

    int ans = MOD;
    vector<int> indexes = {0, 1, 2, 3, 4};
    do {
        int sum = 0;
        rep(i, 5) {
            while (sum % 10 != 0) sum++;
            sum += X.at(indexes.at(i));
        }
        ans = min(ans, sum);
    } while (next_permutation(indexes.begin(), indexes.end()));

    cout << ans << endl;

    return 0;
}

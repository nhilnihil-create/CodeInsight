#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    int leftMax = A + K - 1;
    int rightMin = B - K + 1;
    vector<int> tmp;
    for (int i = A; i <= B; i++) {
        if(i <= leftMax || rightMin<= i) tmp.push_back(i);
    }

    for(int ans : tmp) {
        cout << ans << endl;
    }

    return 0;
}

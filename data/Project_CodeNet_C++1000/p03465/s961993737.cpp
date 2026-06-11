#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int MAX = 4040404;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    long long sum = 0;
    for (int i = 0; i < N; ++i) cin >> A[i], sum += A[i];

    bitset<MAX> dp;
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        dp |= (dp << A[i]);
    }
    long long res;
    for (res = (sum+1)/2; res < MAX; ++res) {
        if (dp[res]) break;
    }
    cout << res << endl;
}

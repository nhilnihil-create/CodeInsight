#include <iostream>
#include <bitset>
using namespace std;

const int MAX_N = 2000;
const int MAX_AI = 2000;

int main() {
    int N, A[MAX_N];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];

    bitset<MAX_N * MAX_AI> dp = 1;
    for (int i = 0; i < N; i++) dp |= (dp << A[i]);

    int median = (sum + 1) / 2;
    while (true) {
        if (dp[median] == 1) break;
        median++;
    }

    cout << median << endl;
    return 0;
}
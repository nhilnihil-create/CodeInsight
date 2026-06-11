#include <bits/stdc++.h>
using namespace std;

vector<int64_t> memo(87, -1);

int64_t lucas(int n) {
    if (n == 0) {
        memo[0] = 2;
        return memo[0];
    }
    if (n == 1) {
        memo[1] = 1;
        return memo[1];
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = lucas(n - 2) + lucas(n - 1);
    return memo[n];
}

int main() {
  int n;
  cin >> n;
  cout << lucas(n) << endl;
}

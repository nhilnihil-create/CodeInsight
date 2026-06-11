#include <bits/stdc++.h>
using namespace std;

int N;
const int SIZE = 100005;
int h[SIZE];
int mem[SIZE];
int K;

int dp(int i) {

    if (i == N - 1) return 0;

    if (i == N - 1) return 0;

    if (mem[i] != -1) return mem[i];

    int ret = INT_MAX;

    for (int j =1; j<=K; j++ ) {
      if (i + j < N)
          ret = min(ret, abs(h[i] - h[i+j]) + dp(i+j));
    }
    return  mem[i] = ret;
}

int main() {

    cin >> N;
    cin >> K;

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    memset(mem, -1, sizeof mem);

    cout << dp(0);
}
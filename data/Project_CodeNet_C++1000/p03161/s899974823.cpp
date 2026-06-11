#include <bits/stdc++.h>
using namespace std;

int N;
int K;

const int INF = 1e9 + 5;

int main() {

    cin >> N;
    cin >> K;

    vector <int> heights(N);

    for (int& height : heights) {
        cin >> height;
    }


    vector <int> dp(N, INF);

    dp[0] = 0;

    for (int i = 0; i < N; i++) {


        for (int j = 1; j<= K; j++) {
        if (i + j < N)
            dp[i + j] = min(dp[i + j], dp[i] + abs(heights[i +j] - heights[i]));
        }
    }

    cout << dp[N - 1];
}
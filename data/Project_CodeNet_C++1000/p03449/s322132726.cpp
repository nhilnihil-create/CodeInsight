#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int A[2][N];
    for (int i = 0 ; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    long long maxSum = 0;
    for (int i = 0; i < N; i++) {
        long long tmpSum = 0;
        // A[0][0]~A[0][i]
        for (int j = 0; j <= i; j++) {
            tmpSum += A[0][j];
        }
        // A[1][i]~A[1][N-1]
        for (int j = i; j < N; j++) {
            tmpSum += A[1][j];
        }
        if (maxSum < tmpSum) {
            maxSum = tmpSum;
        }
    }
    cout << maxSum << endl;
}

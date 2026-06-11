#include <bits/stdc++.h>
using namespace std;

/*
一回しか下にいけないので、どのタイミングでしたに行くかを考えればよい。
it is O(N).
*/

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        cin >> A[0][i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> A[1][i];
    }

    int maxv = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int t = 0; t <= i; t++)
        {
            sum += A[0][t];
        }

        for (int j = i; j < N; j++)
        {
            sum += A[1][j];
        }

        maxv = max(maxv, sum);
    }
    cout << maxv << endl;
}
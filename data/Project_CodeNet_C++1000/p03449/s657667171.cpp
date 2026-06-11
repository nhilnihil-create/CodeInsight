#include <bits/stdc++.h>
using namespace std;

int N;
int A[2][110];

int main()
{
    cin >> N;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    int ma = 0;
    for (int k = 0; k < N; k++)
    {
        int sum = 0;
        for (int j = 0; j <= k; j++)
        {
            sum += A[0][j];
        }
        for (int j = k; j < N; j++) {
            sum += A[1][j];
        }
        ma = max(ma,sum);
    }

    cout << ma << endl;

    return 0;
}

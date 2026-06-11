#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;

    vector<vector<int>> A(2, vector<int>(N));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A.at(i).at(j);
        }
    }

    int lower = 0;
    for (int i = 0; i < N; i++)
    {
        lower += A.at(1).at(i);
    }

    int sum = A.at(0).at(0) + lower;

    int max = sum;
    for (int i = 0; i < N - 1; i++)
    {
        sum += A.at(0).at(i + 1) - A.at(1).at(i);

        if (sum > max)
        {
            max = sum;
        }
    }

    cout << max << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K, A, Sum = 0;
    cin >> N >> M;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        cin >> K;

        for (int a = 0; a < K; a++)
        {
            cin >> A;
            v.push_back(A);
        }
    }

    for (int i = 1; i <= 30; i++)
    {
        if (count(v.begin(), v.end(), i) == N)
        {
            Sum++;
        }
    }

    cout << Sum;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int N, X;
    cin >> N >> X;

    int m[N];
    int min = INT_MAX;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
        sum += m[i];
        if (min > m[i])
            min = m[i];
    }

    int remainder = X - sum;
    if (remainder <= 0)
        cout << N;
    else
    {
        int rest = remainder / min;
        cout << N + rest;
    }
    
    return 0;
}

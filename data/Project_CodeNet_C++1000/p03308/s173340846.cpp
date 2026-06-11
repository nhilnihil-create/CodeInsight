#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int N;
    cin >> N;
    int a;
    int A[N];
    int max = 0;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            a = abs(A[j] - A[i]);
            if (max <= a)
                max = a;
        }
    }

    cout << max;

    return 0;
}

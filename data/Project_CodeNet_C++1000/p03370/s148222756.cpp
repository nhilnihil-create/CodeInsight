#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, X, m[200];
    cin >> N >> X;
    int sum = 0, min;
    for (int i = 0; i < N; i++)
    {

        cin >> m[i];
        sum += m[i];
    }
    min=m[0];
    for (size_t i = 0; i < N; i++)
    {

        if (min > m[i])
        {
            min = m[i];
        }
    }
    int ans = N + (X - sum) / min;
    cout << ans << endl;
}
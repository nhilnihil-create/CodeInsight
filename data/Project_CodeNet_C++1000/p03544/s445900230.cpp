#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int64_t L[87];
    L[0] = 2LL;
    L[1] = 1LL;
    for (int i = 2; i <= N; ++i)
    {
        L[i] = L[i - 1] + L[i - 2];
    }
    cout << L[N] << endl;
}
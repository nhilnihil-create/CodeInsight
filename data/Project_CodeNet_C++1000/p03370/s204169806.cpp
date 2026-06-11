#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X, min = 1 << 30;
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        X -= M;
        if (M < min)
        {
            min = M;
        }
    }

    int cnt = N;
    while (X != X % min)
    {
        cnt++;
        X -= min;
    }
    cout << cnt;
}
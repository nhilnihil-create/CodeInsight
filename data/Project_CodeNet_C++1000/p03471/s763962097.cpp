#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Y;
    cin >> N >> Y;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j + i <= N; j++)
        {
            int a = i, b = j, c = N - i - j;
            if (a * 10000 + b * 5000 + c * 1000 == Y)
            {
                cout << a << ' ' << b << ' ' << c << endl;
                return 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}

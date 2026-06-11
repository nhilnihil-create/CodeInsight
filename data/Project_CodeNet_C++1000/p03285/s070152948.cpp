#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    bool flag = false;
    for (int i = 0; i <= N / 4; i++)
    {
        for (int j = 0; j <= N / 7; j++)
            if (4 * i + 7 * j == N)
            {
                flag = true;
                break;
            }
    }

    if (flag)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
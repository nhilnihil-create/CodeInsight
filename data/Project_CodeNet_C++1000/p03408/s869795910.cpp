#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int main()
{
    int N, M;
    char s[105][105], t[105][105];
    int ans = 0, max = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> t[i];
    }

    for (int k = 0; k < N; k++)
    {
        for (int l = 0; l < N; l++)
        {
            if (strcmp(s[k], s[l]) == 0)
            {

                ans++;
            }
        }
        for (int l = 0; l < M; l++)
        {
            if (strcmp(s[k], t[l]) == 0)
            {
                ans--;
            }
        }
        if (max < ans)
        {
            max = ans;
        }

        ans = 0;
    }

    if (max <= 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << max << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int count = 0;
    rep(i, 1, a + 1)
    {
        bool isEnd = false;
        rep(j, 1, 32)
        {
            if (i == j)
            {
                ++count;
            }
            if (i == a && j == b)
            {
                isEnd = true;
                break;
            }
        }
        if (isEnd)
            break;
    }

    cout << count << endl;

    return 0;
}
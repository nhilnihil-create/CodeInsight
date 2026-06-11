#include <iostream>
using namespace std;

int main()
{
    int h, w, n, sr, sc;
    string s, t;

    cin >> h >> w >> n >> sr >> sc;
    cin >> s;
    cin >> t;

    int left = sc - 1, right = sc - 1, up = sr - 1, down = sr - 1;
    bool yes = true;

    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'L':
            left--;
            break;
        case 'R':
            right++;
            break;
        case 'U':
            up--;
            break;
        case 'D':
            down++;
            break;
        default:
            break;
        }

        if (left < 0 || right > w - 1 || up < 0 || down > h - 1)
        {
            yes = false;
            break;
        }

        switch (t[i])
        {
        case 'L':
            if (right != 0)
            {
                right--;
            }
            break;
        case 'R':
            if (left != w - 1)
            {
                left++;
            }
            break;
        case 'U':
            if (down != 0)
            {
                down--;
            }
            break;
        case 'D':
            if (up != h - 1)
            {
                up++;
            }
            break;
        default:
            break;
        }
    }

    if (yes)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

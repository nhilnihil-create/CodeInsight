#include <iostream>

using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    int sr, sc;
    cin >> sr >> sc;

    std::string s;
    cin >> s;
    std::string t;
    cin >> t;

    bool onboard = true;
    int x, y;

    x = sc;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')
            x--;
        if (x < 1) {
            onboard = false;
            goto End;
        }
        if (t[i] == 'R')
            x = min(x + 1, w);
    }

    x = sc;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R')
            x++;
        if (x > w) {
            onboard = false;
            goto End;
        }
        if (t[i] == 'L')
            x = max(x - 1, 1);
    }

    y = sr;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U')
            y--;
        if (y < 1) {
            onboard = false;
            goto End;
        }
        if (t[i] == 'D')
            y = min(y + 1, h);
    }

    y = sr;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D')
            y++;
        if (y > h) {
            onboard = false;
            goto End;
        }
        if (t[i] == 'U')
            y = max(y - 1, 1);
    }

End:
    cout << (onboard ? "YES" : "NO") << endl;

    return 0;
}

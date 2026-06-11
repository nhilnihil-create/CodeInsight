#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int H, W;
    cin >> H >> W;

    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    vv<char> s(H, v<char>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> s[i][j];
        }
    }

    for (int i = 1; i < H-1; i++)
    {
        for (int j = 1; j < W-1; j++)
        {
            if (s[i][j] == '#' &&s[i][j-1]=='.'&&s[i-1][j]=='.'&&s[i+1][j]=='.'&&s[i][j+1]=='.')
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }


    cout << "Yes" << endl;
    return 0;
}
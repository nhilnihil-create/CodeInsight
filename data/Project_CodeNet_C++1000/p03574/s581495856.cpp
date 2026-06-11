#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int h, w;
    cin >> h >> w;
    string s[h];
    rep(i, h) cin >> s[i];
    vector<vector<string>> out(h, vector<string>(w));
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
    rep(i, h)
    {
        rep(j, w)
        {
            int cnt = 0;
            if (s[i][j] == '#')
            {
                out[i][j] = '#';
                continue;
            }
            rep(k, 8)
            {
                int x = j + dx[k];
                int y = i + dy[k];
                if (x >= 0 && y >= 0 && x < w && y < h)
                {
                    if (s[y][x] == '#')
                        cnt++;
                }
            }
            out[i][j] = to_string(cnt);
        }
    }
    rep(i, h)
    {
        rep(j, w) cout << out[i][j];
        cout << endl;
    }
    return 0;
}
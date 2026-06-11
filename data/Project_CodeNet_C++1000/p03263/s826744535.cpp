#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// const int MAX = 1010;

int grid[510][510];

struct Move
{
    int y;
    int x;
    int yd;
    int xd;
};

int main()
{
    int H, W;
    cin >> H >> W;
    vector<Move> ans;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j == W - 1)
            {
                if (i != H - 1)
                {
                    if (grid[i][j] % 2 != 0)
                    {
                        --grid[i][j];
                        ++grid[i + 1][j];
                        Move m = {i, j, i + 1, j};
                        ans.push_back(m);
                    }
                }
            }
            else
            {
                if (grid[i][j] % 2 != 0)
                {
                    --grid[i][j];
                    ++grid[i][j + 1];
                    Move m = {i, j, i, j + 1};
                    ans.push_back(m);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a.y + 1 << ' ' << a.x + 1 << ' ' << a.yd + 1 << ' ' << a.xd + 1 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

#define endl     '\n'

using namespace std;

typedef long long ll;

const int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
const char dir[] = {'D', 'U', 'R', 'L'};

void Fast() { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }
void File()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif
}

const int N = 1e3 + 9, M = 1e3 + 9, oo = 0x3f3f3f3f;

/**----------------->>  Quality Over Quantity  <<----------------**/

int n, m, dis[N][N];
char grid[N][M];
queue <array <int, 2>> Q;

bool valid(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m && dis[r][c] == oo;//grid[r][c] == '.';
}

void BFS()
{
    array <int, 2> cell;
    int r, c;
    while(Q.size())
    {
        cell = Q.front(); Q.pop();
        for(int i = 0; i < 4; ++i)
        {
            r = cell[0] + dx[i];
            c = cell[1] + dy[i];
            if(!valid(r, c)) continue;
            dis[r][c] = dis[cell[0]][cell[1]] + 1;
            Q.push({r, c});
        }
    }
}

void Solve()
{
    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);

    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
    {
        cin >> grid[i][j];
        if(grid[i][j] == '#')
            Q.push({i, j}), dis[i][j] = 0;
    }

    BFS();

    int ans = 0;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
        if(dis[i][j] > ans) ans = dis[i][j];

    cout << ans << endl;
}

void MultiTest(bool Tests = 0)
{
    int tc = 1; (Tests) && (cin >> tc);
    for(int i = 1;  i <= tc; ++i)
        Solve();
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast();  MultiTest();
}

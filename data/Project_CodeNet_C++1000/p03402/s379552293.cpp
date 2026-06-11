#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
const int MAXN = 100;
const int HALFN = MAXN / 2;
int main()
{
    int a, b;
    cin >> a >> b;

    --a, --b;
    cout << MAXN << ' ' << MAXN << endl;
    
    char ans[MAXN][MAXN];
    rep(i, 0, HALFN)
    rep(j, 0, MAXN)
        ans[i][j] = '#';

    rep(i, HALFN, MAXN)
    rep(j, 0, MAXN)
        ans[i][j] = '.';
    
    rep(i, 0, a)
    {
        int x = i / HALFN;
        int y = i % HALFN;
        ans[2 * x][2 * y] = '.';
    }
    rep(i, 0, b)
    {
        int x = i / HALFN;
        int y = i % HALFN;
        ans[2 * x + HALFN + 1][2 * y] = '#';
    }

    rep(i, 0, MAXN)
    {
        rep(j, 0, MAXN)
            printf("%c", ans[i][j]);
        cout << endl;
    }
    return 0;
}
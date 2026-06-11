#include<iostream>
using namespace std;

const int N = 1e5 + 7;

bool vis[N][100];

int suma(int n)
{
    int res = 0;
    while(n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int n;

void dfs(int r, int s)
{
    if(s >= 50) return;
    if(vis[r][s]) return;
    vis[r][s] = 1;
    for(int i = 0; i < 10; i++)
        dfs((10 * r + i) % n, s + i);
}

int main()
{
    cin >> n;
   
    dfs(0, 0);
    //while(n % 2 == 0) n /= 2;
    //while(n % 5 == 0) n /= 5;
    int res = 1e9;
    for(int i = 1; i < 99; i++)
        if(vis[0][i]) res = min(res, i);
    cout << res << "\n";
    return 0;
}

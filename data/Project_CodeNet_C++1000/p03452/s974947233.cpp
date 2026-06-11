#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2000005 ;

int pre[maxn];
int dis[maxn];

int Find(int x)
{
     if(pre[x]==x)
        return x;

    int r=Find(pre[x]);
    dis[x]=dis[pre[x]]+dis[x];

    return pre[x]=r;
}

int Union(int x, int y, int z)
{
    int fx = Find(x);
    int fy = Find(y);

    if (fx == fy)
        return (z == dis[y] - dis[x]);

    pre[fy] = fx;

    dis[fy] = dis[x] + z - dis[y];

    return 1;
}

int x[maxn];
int y[maxn];
int z[maxn];

int main()
{
    int n, m;
    int flag = 1;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        pre[i]=i;

    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    for(int i =1;i<=m;i++)
    {
        flag = Union(x[i], y[i], z[i]);
        if(flag == 0)
            goto end;
    }

end:
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

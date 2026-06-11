#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <deque>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#define pi acos(-1)

const int maxn = 1000000 + 5;

int father[maxn];
int dis[maxn];

int Find(int x)
{
    if(father[x] == x)
        return x;

    int r = Find(father[x]);

    dis[x] = dis[father[x]] + dis[x];

    return father[x] = r;
}

int Union(int x, int y, int z)
{
    int fx = Find(x);
    int fy = Find(y);

    if (fx == fy)
        return (z == dis[y] - dis[x]);

    father[fy] = fx;

    dis[fy] = dis[x] + z - dis[y];

    return 1;
}

int main()
{
    int N, M;
    int flag = 1;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        father[i]=i;

    for (int i = 1; i <= M; i++)
    {
        int x, y, z;

        cin >> x >> y >> z;

        if (flag)
            flag = Union(x, y, z);
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

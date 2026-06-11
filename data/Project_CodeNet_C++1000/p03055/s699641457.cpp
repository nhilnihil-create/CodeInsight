#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> L[200005];
int n, D, nr, nodMax, uz[200005], dp[200005];

void DFS(int x);

int main()
{
    int x, y;

    cin >> n;
    for (int i=1;i<n;i++)
    {
        cin >> x >> y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    DFS(1);
    memset(uz,0,sizeof(uz));
    DFS(nodMax);
    dp[0] = 1;
    dp[1] = 0;
    for (int i=2;i<=D;i++)
        dp[i] = (dp[i-2] == 0 || dp[i-1] == 0);
    if (dp[D])
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}

void DFS(int x)
{
    uz[x] = 1;
    if (nr > D)
    {
        D = nr;
        nodMax = x;
    }
    for (int i:L[x])
    {
        if (!uz[i])
        {
            nr++;
            DFS(i);
            nr--;
        }
    }
}
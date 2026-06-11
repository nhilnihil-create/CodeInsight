#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> ve[10005];
int a[10005];
int b[10005];
int sum;
queue<int> qu;
int ans[10005];
int cnt;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++)
    {
        sum += a[i];
    }
    printf("%d\n", sum);
    for(int i = 1; i <= n; i++) b[i] = ve[i].size();
    for(int i = 1; i <= n; i++) if(b[i] == 1) qu.push(i), ans[i] = a[cnt], cnt++;
    while(!qu.empty())
    {
        int t1 = qu.front();
        qu.pop();
        for(int i = 0; i < ve[t1].size(); i++)
        {
            b[ve[t1][i]]--;
            if(b[ve[t1][i]] > 1 || ans[ve[t1][i]]) continue;
            ans[ve[t1][i]] = a[cnt];
            cnt++;
            qu.push(ve[t1][i]);
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}

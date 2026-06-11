#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000 + 10;
vector<int> e[N];
LL v[N];
queue<int> q;
LL c[N];
int main()
{
    LL sum = 0, maxn = -1;
    int n;
    scanf("%d", &n);
    for (int i = 1, a, b; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }


    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &c[i]);
        sum += c[i];
        maxn = max(maxn, c[i]);
    }
    sort(c + 1, c + n + 1);

    int k = n;
    memset(v, -1, sizeof v);
    q.push(1);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        v[p] = c[k--];
        for (int i : e[p])
            if(v[i] == -1) 
                q.push(i);
    }
    
    printf("%lld\n", sum - maxn);
    for(int i = 1; i <= n; i++) {
        printf("%lld ", v[i]);
    }
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 110, M = N * N;

int x[N], y[N], a[N], b[N];

int n;
int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool st[N];
int match[N];

bool find(int u)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(!match[j] || find(match[j]))
            {
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)  scanf("%d%d", &x[i], &y[i]);
    for(int i = 1; i <= n; i ++)  scanf("%d%d", &a[i], &b[i]);
    
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(x[i] < a[j] && y[i] < b[j])
                add(i, j);
    
    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        memset(st, 0, sizeof st);
        if(find(i))  res ++;
    }
    printf("%d", res);
	return 0;
}
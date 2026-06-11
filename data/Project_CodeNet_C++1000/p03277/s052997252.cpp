#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
const int M = (1<<18);
ll p;
int n;
int t [N];
int tree [M+M];

void update (int u){
    for (u+=M; u!=0; u/=2)
        tree[u]++;
}

int query (int a, int b)
{
    a+=M;
    b+=M;
    int res = tree[a]+tree[b];
    while (a/2 != b/2)
    {
        if (a%2==0) res += tree[a+1];
        if (b%2==1) res += tree[b-1];
        a/=2;
        b/=2;
    }
    return res;
}

bool check (int m)
{
    int i;
    for (i=0; i<M+M; i++)
        tree[i] = 0;
    update(N);
    ll out = 0;
    int pre = 0;
    for (i=1; i<=n; i++)
    {
        pre += ((t[i]<=m) ? -1 : 1);
        out += query(N+pre+1, N+n+1);
        update(N+pre);
    }
    if (p%2==0) return (2*out >= p+2);
    if (p%2==1) return (2*out >= p+1);
}

int main ()
{
    int i, a, b;
    scanf ("%d",&n);
    p = (1ll*(n+1)*n)/2;
    for (i=1; i<=n; i++)
        scanf ("%d",&t[i]);
    a = -1;
    b = 1000000001;
    while (b-a>1)
        (check((a+b)/2) ? b : a) = (a+b)/2;
    printf ("%d\n", b);
    return 0;
}

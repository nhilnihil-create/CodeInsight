#include <bits/stdc++.h>
#define N 21

using namespace std;
int n, A[N][N], F[N][1<<21], d[N][1<<21];

long long Magic(int i, int check)
{
    if(i==n) return 1;
    if(d[i][check]) return F[i][check]; d[i][check]=1;
    long long res = 0;
    for(int j=0; j<n; j++)
    {
        if((check>>j)&1) continue;
        if(A[i][j])
            res = (res+Magic(i+1, check^(1<<j)))%1000000007;
    }
    return F[i][check]=res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>A[i][j];
    cout<<Magic(0, 0);
    return 0;
}

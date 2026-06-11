#include <bits/stdc++.h>
#define N 505
using namespace std;
int n,m,q,c[N][N],f[N][N],l,r;
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)cin>>l>>r,c[l][r]++;
    for(int i=1;i<=n;i++)f[i][i]=c[i][i];
    for(int i=1;i<=n-1;i++)
        f[i][i+1]=c[i][i+1]+f[i+1][i+1]+f[i][i];
    for(int k=2;k<=n-1;k++)
        for(int i=1;i<=n-k;i++)
            f[i][i+k]=c[i][i+k]+f[i][i+k-1]+f[i+1][i+k]-f[i+1][i+k-1];
    for(int i=1;i<=q;i++)cin>>l>>r,cout<<f[l][r]<<endl;
    return 0;
}
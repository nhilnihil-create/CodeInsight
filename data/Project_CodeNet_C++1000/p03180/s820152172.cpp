#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[20][20],v[20],n;
ll f[65540],sum[65540];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<(1<<n);i++){
        int num=0;
        for(int j=0;j<n;j++)
            if(i>>j&1)v[++num]=j;
        ll ss=0;
        for(int j=1;j<=num;j++){
            for(int k=j+1;k<=num;k++)ss+=a[v[j]][v[k]];
        }
        f[i]=sum[i]=ss;
    }
    for(int j=0;j<(1<<n);j++){
        for(int i=j;i;i=(i-1)&j)f[j]=max(f[j],f[i^j]+sum[i]);
    }
    printf("%lld\n",f[(1<<n)-1]);
    return 0;
}

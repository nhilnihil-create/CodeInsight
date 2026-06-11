#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
typedef long long ll;
int a[1000][1000];

void solve(int m){
    if(m==2){a[0][0]=1;a[1][0]=1;return;}
    int nn=m*(m-1)/2;
    rep(i,0,m-1){a[m-1][i]=nn-i;a[i][m-2]=nn-i;}
    solve(m-1);
    return;
}

int main()
{
    int n,k=-1;cin>>n;
    for(k=0;k<1000;k++){if(k*(k-1)/2==n) break;}
    if(k>990){printf("No\n");return 0;}
    printf("Yes\n");
    printf("%d\n",k);
    solve(k);
    rep(i,0,k){
        printf("%d ",k-1);
        rep(j,0,k-1){printf("%d",a[i][j]);printf(j==k-2?"\n":" ");}
    }
    return 0;
}

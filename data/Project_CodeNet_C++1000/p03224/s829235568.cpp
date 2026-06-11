#include<stdio.h>
#include<string.h>
#include<utility>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
 
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
 
 
int main()
{
    int n;
    scanf("%d\n",&n);
    int a[100005]={};
    for(int i=2;i<500;i++)if(i*(i-1)/2<=100000)a[i*(i-1)/2]=i;
    if(a[n]==0)
    {
        printf("No\n");
        return 0;
    }
    int ban[500][500]={};
    int po=0;
    int max=0;
    REP(i,a[n]-1)
    {
        int y=0;
        while(y!=po)
        {
            ban[po][y+1]=ban[y][po];
            y++;
        }
        po++;
        for(int j=1;j<a[n];j++)
        {
            if(ban[i][j]==0)
            {
                ban[i][j]=++max;
            }
        }
    }
    printf("Yes\n%d\n",a[n]);
    REP(i,a[n]-1)
    {
        printf("%d",a[n]-1);
        REP(j,a[n]-1)printf(" %d",ban[i][j+1]);
        printf("\n");
    }
    printf("%d",a[n]-1);
    REP(i,a[n]-1)printf(" %d",ban[i][a[n]-1]);
    printf("\n");
    return 0;
}
#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
#define MAX 25
#define MOD 1000000000
#define NINF -1000000000000000000
vector<int> Graph[MAX];
bool visit[MAX];
int sum[MAX];
bool makeGraph(int n)
{
    int arr[n+1];
    int sum[n+1];
    int i=0;
    arr[i]=0;
    sum[i]=0;
    int j;
    for(i=1,j=(n/2)*2;i<=n;i++,j--)
    {
        sum[i]=0;
        if(i<j)
        {
            arr[i]=j;
        }
        else
        {
            arr[i]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(arr[i]==j) continue;
            sum[i]+=j;
            sum[j]+=i;
        }
    }
    for(i=2;i<=n;i++)
    {
        if(sum[i]!=sum[i-1]) return false;
    }
    printf("%d\n",n*(n-1)/2-(n/2));
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(arr[i]==j) continue;
            printf("%d %d\n",i,j);
        }
    }
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    bool ans=makeGraph(n);
    return 0;
}

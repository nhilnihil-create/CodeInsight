#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
#define MAX 200005
#define MOD 1000000000
#define NINF -1000000000000000000
int pos[MAX];
int length[MAX];
int main()
{
    int n,i,inp,ans=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&inp);
        inp--;
        pos[inp]=i;
    }
    length[n-1]=1;
    for(i=n-2;i>=0;i--)
    {
        length[i]=1;
        if(pos[i+1]>pos[i])
        {
            length[i]=length[i]+length[i+1];
        }
        ans=max(ans,length[i]);
    }
    ans=n-ans;
    printf("%d",ans);
    return 0;
}

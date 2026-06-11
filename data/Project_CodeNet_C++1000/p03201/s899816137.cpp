#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
unordered_map<int,int>vis;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),vis[a[i]]++;
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        if(!vis[a[i]]) continue;
        vis[a[i]]--;
        for(int j=1<<30;j&&j>=a[i];j>>=1)
        {
            if(vis[j-a[i]])
            {
                vis[j-a[i]]--;
                ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
}

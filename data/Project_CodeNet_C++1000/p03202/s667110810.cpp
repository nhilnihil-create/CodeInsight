#include<bits/stdc++.h>
using namespace std;
int n,a[200001],s[200001];
map<int,int> mp;
bool judge(int x)
{
    mp.clear();
    int cnt=0;
    for(int i=2;i<=n;i++)
        if(a[i]<=a[i-1])
        {
            if(x==1) return false;
            while(cnt&&s[cnt-1]>a[i])
                mp[s[cnt-1]]=0,cnt--;
            int t=a[i];
            while(mp[t]+1>=x&&t>0) mp[t]=0,t--;
            if(t<=0) return false;
            mp[t]++;
            s[cnt++]=t;
        }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l=1,r=n,ans;
    while(l<=r)
    {
        int m=l+r>>1;
        if(judge(m)) ans=m,r=m-1;
        else l=m+1;
    }
    printf("%d\n",ans);
}

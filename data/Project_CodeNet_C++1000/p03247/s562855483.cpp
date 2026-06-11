#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,x[N],y[N];
string ans;
vector<int>v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=2;i<=n;i++)
        if((abs(x[i])+abs(y[i]))%2!=(abs(x[i-1])+abs(y[i-1]))%2)
    {
        printf("-1\n");return 0;
    }
    if((abs(x[1])+abs(y[1]))%2==0) v.push_back(1);
    for(int i=0;i<=30;i++) v.push_back(1<<i);
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf(i==v.size()-1?"%d\n":"%d ",v[i]);
    for(int i=1;i<=n;i++)
    {
        ans="";
        for(int j=v.size()-1;j>=0;j--)
        {
            if(abs(x[i])>abs(y[i]))
            {
                if(x[i]<0) x[i]+=v[j],ans+='L';
                else x[i]-=v[j],ans+='R';
            }
            else
            {
                if(y[i]<0) y[i]+=v[j],ans+='D';
                else y[i]-=v[j],ans+='U';
            }
        }
        for(int i=ans.size()-1;i>=0;i--)
            printf("%c",ans[i]);
        putchar('\n');
    }
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1024*1024*2+50;
int a[200000+50];
int A[200000+50];
int p[maxn];
int b[200000+50];
int pre[200000+50];
int nx[200000+50];
int n;
long long ans=0;
int main()
{   

    scanf("%d",&n);
    for(int i=1;i<=n;i++)  //区间最长不超过20
    scanf("%d",&A[i]);
    long long zero=0;
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        if(A[i]==0)
        zero++;
        else
        {
            if(zero==1) ans++;
            else
            {
                ans+=(zero*(zero-1))/2;
                ans+=zero;
            }
            
            a[++tot]=A[i];
            pre[tot]=zero;
            zero=0;
        }
    }
    if(zero)
    {
        if(zero==1) ans++;
            else
            {
                ans+=(zero*(zero-1))/2;
                ans+=zero;
            }
    }
    pre[tot+1]=zero;
    n=tot;
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]^b[i-1];
    }
    for(int i=1;i<=n;i++)
    a[i]=a[i]+a[i-1];
    
    
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j+i-1<=n;j++)
        {
            if((b[i+j-1]^b[j-1])==(a[i+j-1]-a[j-1]))
            {   
              //  printf("%d %d  %d %d %d %d\n",b[i+j-1],b[j-1],a[i+j-1],a[j-1],b[i+j-1]^b[j-1],a[i+j-1]-a[j-1]);
                long long pre0=pre[j];
                long long nx0=pre[i+j];
                ans+=(pre0+1)*(nx0+1);
               // printf("%d %d %d\n",ans,j,i+j-1);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}   
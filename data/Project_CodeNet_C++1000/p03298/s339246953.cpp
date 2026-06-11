#include<bits/stdc++.h>
#define ul unsigned long long
#define pi pair<ul,ul>
using namespace std;
const ul p=19260817;
int n,m,la,lb,lc;
char str[50],a[50],b[50],c[50];
map<pi,int>cnt;
int main()
{
    int n;
    scanf("%d",&n);
    m=(1<<n);
    scanf("%s",str);
    for(int s=0;s<m;++s)
    {
        ul fi=0,se=0;
        for(int i=0;i<n;++i)
            if(s>>i&1) fi=fi*p+str[i];
            else se=se*p+str[i];
        cnt[pi(fi,se)]++;
    }
    long long ans=0;
    for(int s=0;s<m;++s)
    {
        la=lb=lc=0;
        for(int i=0;i<n;++i)
            if(s>>i&1) a[la++]=str[i+n];
            else b[lb++]=str[i+n];
        ul fi=0,se=0;
        for(int i=0;i<lb;++i) fi=fi*p+b[lb-1-i];
        for(int i=0;i<la;++i) se=se*p+a[la-1-i];
        ans+=cnt[pi(fi,se)];
    }
    printf("%lld\n",ans);

    return 0;
}

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
int n,a[N];
bool solve(int m)
{
    stack<pair<int,int> >s;
    for(int i=1;i<=n;i++)
    {
        if(s.empty()) s.push({a[i],1});
        else
        {
            if(a[i]>s.top().fi) s.push({a[i],1});
            else
            {
                if(m==1) return false;
                while(!s.empty()&&s.top().fi>a[i]) s.pop();
                if(s.empty()||s.top().fi<a[i]) s.push({a[i],2});
                else
                {
                    int now=s.top().fi;
                    while(!s.empty()&&s.top().fi==now&&s.top().se==m)
                    {
                        now--;s.pop();
                    }
                    if(s.empty()&&now==0) return false;
                    if(!s.empty()&&s.top().fi==now)
                    {
                        int p=s.top().se+1;s.pop();
                        s.push({now,p});
                    }
                    else s.push({now,2});
                }
            }
        }
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
        if(solve(m)) ans=m,r=m-1;
        else l=m+1;
    }
    printf("%d\n",ans);
}

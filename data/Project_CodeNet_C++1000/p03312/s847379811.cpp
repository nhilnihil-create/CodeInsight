#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],r=100000000000000000,pr[200005],p1,p2,p3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pr[i]=pr[i-1]+a[i];
    }

    for(long long i=2;i<=n-2;i++)
    {
        p1=upper_bound(pr,pr+n+1,pr[i]/2)-pr;
        p3=upper_bound(pr,pr+n+1,pr[i]+(pr[n]-pr[i])/2)-pr;
        for(int j1=p1-1;j1<=p1;j1++)
            for(int j3=p3-1;j3<=p3;j3++)
            {
                if(j1==0||i<=j1||i>=j3||j3==n)
                    continue;
                else
                    r=min(r,max(pr[j1],max(pr[i]-pr[j1],max(pr[j3]-pr[i],pr[n]-pr[j3])))-min(pr[j1],min(pr[i]-pr[j1],min(pr[j3]-pr[i],pr[n]-pr[j3]))));
            }
    }

    cout<<r<<endl;

    return 0;
}

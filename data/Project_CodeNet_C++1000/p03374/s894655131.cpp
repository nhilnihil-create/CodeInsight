#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define PI acos(-1.0)

typedef long long ll;
const int maxn=1e5+10;
ll max1[maxn],max2[maxn];
ll sum,n,c,maxx,ans;
ll v[maxn],x[maxn];

int main()
{
    cin >> n >> c;
    for(int i=0;i<n;i++)
        cin >> x[i] >> v[i];
    for(int i=0;i<n;i++)
    {
        if(i==0)
            sum+=v[i]-x[i];
        else
            sum+=(v[i]-x[i]+x[i-1]);
        ans=max(ans,sum);
//        maxx=max(ans,maxx);
        max1[i]=ans;
    }
    maxx=max(ans,maxx);
//    cout << maxx << endl;
    ans=sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
            sum+=(v[i]-c+x[i]);
        else
            sum+=(v[i]-x[i+1]+x[i]);
        ans=max(ans,sum);
        max2[i]=ans;
    }
    maxx=max(ans,maxx);
//    cout << maxx << endl;
    sum=ans=0;
//    for(int i=0;i<n;i++)
//    {
//        printf("%lld %lld\n",max1[i],max2[n-1-i]);
//    }
    for(int i=0;i<n-1;i++)
    {
        if(i==0)
            sum+=(v[i]-2*x[i]);
        else
            sum+=(v[i]-2*(x[i]-x[i-1]));
        maxx=max(maxx,sum+max2[i+1]);
    }
    sum=0;
    for(int i=n-1;i>0;i--)
    {
        if(i==n-1)
            sum+=(v[i]-2*(c-x[i]));
        else
            sum+=(v[i]-2*(x[i+1]-x[i]));
        maxx=max(maxx,sum+max1[i-1]);
//        cout << maxx << endl;
    }
    cout << maxx << endl;
    return 0;
}

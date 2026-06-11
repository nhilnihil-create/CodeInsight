#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],b[200005],rez;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    for(long long i=0;i<n;i++)
        cin>>b[i];

    for(long long i=0;i<30;i++)
    {
        long long a1[n],b1[n],t=(1<<i),cnt=0;
        for(long long j=0;j<n;j++)
        {
            a1[j]=a[j]%(2*t);
            b1[j]=b[j]%(2*t);
        }
        sort(a1,a1+n);
        sort(b1,b1+n);
        for(long long j=0;j<n;j++)
        {
            long long p1=lower_bound(a1,a1+n,t-b1[j])-a1;
            long long p2=lower_bound(a1,a1+n,2*t-b1[j])-a1;
            long long p3=lower_bound(a1,a1+n,3*t-b1[j])-a1;
            long long p4=lower_bound(a1,a1+n,4*t-b1[j])-a1;
            cnt+=max((long long)0,p2-p1)+max((long long)0,p4-p3);
        }
        if(cnt%2==1)
            rez+=t;
    }

    cout<<rez<<endl;

    return 0;
}

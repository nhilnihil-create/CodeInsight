#include <bits/stdc++.h>
using namespace std;

long long n,a[100005],r1,r2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);
    r2=a[n-1];

    long long q1=lower_bound(a,a+n,a[n-1]/2+(a[n-1]%2==1))-a;
    long long q2=q1-1;
    if(q1==0)
    {
        r1=a[q1];
        cout<<r2<<" "<<r1<<endl;
    }
    else if(q1==n-1)
    {
        r1=a[q2];
        cout<<r2<<" "<<r1<<endl;
    }
    else
    {
        if(a[n-1]%2==0)
        {
            long long d=a[n-1]/2;
            long long d1=llabs(d-a[q1]),d2=llabs(d-a[q2]);
            if(d1<d2)
                r1=a[q1];
            else
                r1=a[q2];
        }
        else
        {
            float d=a[n-1]/2+0.5;
            float d1=fabs(d-a[q1]),d2=fabs(d-a[q2]);
            if(d1<d2)
                r1=a[q1];
            else
                r1=a[q2];
        }
        cout<<r2<<" "<<r1<<endl;
    }


    return 0;
}

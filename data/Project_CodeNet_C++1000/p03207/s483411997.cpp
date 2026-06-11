#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[1001],b,c,e,d,f,t,i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
        cin>>a[i];
    sort(a,a+t);
    b=a[t-1]/2;
    for(i=0;i<t-1;i++)
        b+=a[i];
    cout<<b<<endl;
    return 0;
}

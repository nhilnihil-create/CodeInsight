#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p=0,q=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
          p+=a[i];
        else
          q+=a[i];
    }
    cout<<p-q;

    return 0;
}


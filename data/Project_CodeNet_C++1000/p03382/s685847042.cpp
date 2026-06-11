#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    int a[100005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int l=a[n-1];
    cout<<l<<" ";
    if(l%2)
    {
         for(int i=0;i<n;i++)
    {
        if(a[i]==l/2||a[i]==(l+1)/2)
        {

            cout<<a[i]<<endl;
            return 0;
        }
        if(a[i]>(l+1)/2)
        {
            if(l-a[i]>a[i-1])
                cout<<a[i];
            else
                cout<<a[i-1];
                cout<<endl;
            return 0;
        }


    }
    }
    else
    {
         for(int i=0;i<n;i++)
    {
        if(a[i]==l/2)
        {

            cout<<a[i]<<endl;
            return 0;
        }
        if(a[i]>l/2)
        {
            if(l-a[i]>a[i-1])
                cout<<a[i];
            else
                cout<<a[i-1];
                cout<<endl;
            return 0;
        }

    }
    }
    cout<<a[n-2]<<endl;
    return 0;


}

#include <bits/stdc++.h>
using namespace std;
int main()
{
       int n,a=0,s=0;cin>>n;
       int x[n];
       for(int i=0;i<n;i++)
        cin>>x[i];
       sort(x,x+n);
       reverse(x,x+n);
       for(int i=0;i<n;i+=2){
        a+=x[i];
        if(i==n-1)
            break;
        s+=x[i+1];
       }
       cout<<abs(a-s);
    return 0;
   }
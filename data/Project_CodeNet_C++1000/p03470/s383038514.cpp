#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0;cin>>n;
    int k[n];
    for(int i=0;i<n;i++)
        cin>>k[i];
        sort(k,k+n);
    for(int i=0;i<n;i++)
        if(k[i]!=k[i+1])
            s++;

    cout<<s;
    return 0;
   }
#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{

        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        cout<<1+(n-k+k-2)/(k-1)<<endl;
}
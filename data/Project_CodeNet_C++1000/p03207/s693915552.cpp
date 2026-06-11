#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[11],sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        sum+=a[i];
    }
    cout<<sum+(a[n-1]/2);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3],sum;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    sum=2*a[2]-a[0]-a[1];
    if(sum%2==0)cout<<sum/2;
    else cout<<sum/2+2;
    return 0;
}
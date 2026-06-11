#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort( a , a+3);
    int ans=0;
    ans += a[2] -a[1];
    a[0] += a[2] -a[1];
    ans +=ceil ((a[2] -a[0])/double(2) ) + (a[2] -a[0])%2;
    cout<<ans;

}
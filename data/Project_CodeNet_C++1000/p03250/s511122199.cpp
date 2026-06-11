//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,a[3],ans;
    string s;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    ans=a[2]*10+a[1];
    return cout<<ans+a[0]<<endl,0;
    return 0;
}




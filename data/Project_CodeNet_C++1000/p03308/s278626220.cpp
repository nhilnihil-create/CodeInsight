//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,t,n,j,k,sum=0,cpn;
    string s;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    cout<<a[n-1]-a[0]<<endl;

    return 0;
}




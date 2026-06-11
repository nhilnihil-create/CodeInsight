//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,t,n=3,j;
    string s;
    ll a[n];
    for(i=0;i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll cost=0;
    for(i=1;i<n; i++){
        cost+=abs(a[i]-a[i-1]);
    }
        cout<<cost<<endl;
    return 0;
}




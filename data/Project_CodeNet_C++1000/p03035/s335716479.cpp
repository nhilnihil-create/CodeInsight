#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll n,k,i,j;
    cin>>n>>k;
    if(n>=13){
        cout<<k;
    }
    else if(n>=6&&n<=12)
        cout<<k/2;
        else
    cout<<0;


    return 0;
}




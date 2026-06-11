#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    s[k-1]+=32;
    cout<<s<<endl;



    return 0;
}




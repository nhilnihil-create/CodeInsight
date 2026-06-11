#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    if (n==1 && m==1)
        cout<<"1\n";
    else if (n==1)
        cout<<m-2<<endl;
    else if (m==1)
        cout<<n-2<<endl;
    else
        cout<<(n-2)*(m-2)<<endl;
}
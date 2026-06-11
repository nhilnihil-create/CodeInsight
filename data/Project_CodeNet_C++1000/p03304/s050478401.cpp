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
    ll n,m,d;
    cin>>n>>m>>d;
    cout<<fixed;
    cout<<setprecision(10);
    if (d==0)
        cout<<(1.0/n)*(m-1)<<endl;
    else
        cout<<(2.0*(n-d))/(n*n)*(m-1)<<endl;
}
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
    int a,b;
    cin>>a>>b;
    if (a==b)
        cout<<2*a<<endl;
    else
        cout<<2*max(a,b)-1<<endl;
}
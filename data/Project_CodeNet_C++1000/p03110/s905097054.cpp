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
    int n,i;
    cin>>n;
    double x,tot=0;
    string u;
    for (i=0;i<n;i++)
    {
        cin>>x>>u;
        if (u=="JPY")
            tot+=x;
        else
            tot+=380000*x;
    }
    cout<<tot<<endl;
}
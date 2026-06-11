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
    int r;
    cin>>r;
    if (r<1200)
        cout<<"ABC\n";
    else if (r<2800)
        cout<<"ARC\n";
    else
        cout<<"AGC\n";
}
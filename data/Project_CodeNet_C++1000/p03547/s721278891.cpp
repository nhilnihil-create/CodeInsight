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
    char x,y;
    cin>>x>>y;
    if (x>y)
        cout<<">\n";
    else if (x<y)
        cout<<"<\n";
    else
        cout<<"=\n";
}
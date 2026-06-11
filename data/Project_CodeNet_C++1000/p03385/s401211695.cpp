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
    int i;
    string s;
    cin>>s;
    set<char> t;
    for (i=0;i<3;i++)
        t.insert(s[i]);
    if (t.size()==3)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
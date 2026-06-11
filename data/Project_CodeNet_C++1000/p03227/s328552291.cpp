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
    string s;
    cin>>s;
    if (s.size()==2)
        cout<<s<<endl;
    else
    {
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
}
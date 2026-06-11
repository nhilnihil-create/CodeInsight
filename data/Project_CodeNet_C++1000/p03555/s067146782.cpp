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
    string s1,s2;
    cin>>s1;
    cin>>s2;
    if (s1[0]==s2[2] && s1[1]==s2[1] && s1[2]==s2[0])
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
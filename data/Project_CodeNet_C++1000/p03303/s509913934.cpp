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
    int w,i;
    cin>>s;
    cin>>w;
    for (i=0;i<s.size();i+=w)
        cout<<s[i];
}
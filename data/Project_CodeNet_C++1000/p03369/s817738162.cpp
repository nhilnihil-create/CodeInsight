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
    int ans=700+100*((s[0]=='o')+(s[1]=='o')+(s[2]=='o'));
    cout<<ans<<endl;
}
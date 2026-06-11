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
    int k,i,j,f=0;
    string s,ans;
    cin>>s;
    cin>>k;
    set<string> subs;
    for (i=0;i<s.size();i++)
    {
        for (j=1;j<=k;j++)
            subs.insert(s.substr(i,j));
    }
    for (string a: subs)
    {
        k--;
        if (k==0)
        {
            ans=a;
            break;
        }
    }
    cout<<ans<<endl;
}
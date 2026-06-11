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
    int a,b,h=1,cur=2,ans;
    cin>>a>>b;
    while (1)
    {
        if (h<a)
        {
            h+=cur;
            cur++;
        }
        else
        {
            if ((h-a)==(h+cur-b))
            {
                ans=h-a;
                break;
            }
            h+=cur;
            cur++;
        }
    }
    cout<<ans<<endl;
}
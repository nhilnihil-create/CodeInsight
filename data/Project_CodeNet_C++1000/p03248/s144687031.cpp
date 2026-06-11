#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 



int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,j,k,x,y,t,m;
    string s;
    cin >> s;
    n=sz(s);
    ll f=0,prev=0,last=1;
    for(i=0;i<n-1;i++)
        if(s[i]!=s[n-2-i])f=1;
    if(s[n-1]=='1' || s[0]=='0')f=1;

    if(f)
        cout<<-1<<endl;
    else
    {
        for(i=1;i<=n;i++)
        {
            if(s[i-1]=='0')
                continue;
            for(j=1;j<=i-prev;j++)
                cout<<last<<" "<<last+j<<endl;
            last=last+j-1;
            prev=i;
        }   
    }
}
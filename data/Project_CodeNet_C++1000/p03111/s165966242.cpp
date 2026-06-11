#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,b,c;
ll l[10];
ll mini=1e18;
ll rec(string s)
{
    if(s.size()==n)
    {
        ll a1=0,b1=0,c1=0;
        ll cost=0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                if(a1!=0)
                {
                    cost+=10;
                }
                a1+=l[i+1];
            }
            else if(s[i]=='2')
            {
                if(b1!=0)
                {
                    cost+=10;
                }
                b1+=l[i+1];
            }
            else if(s[i]=='3')
            {
                if(c1!=0)
                {
                    cost+=10;
                }
                c1+=l[i+1];
            }
        }
        if(a1!=0 && b1!=0 && c1!=0)
        {
            cost+=abs(a1-a)+abs(b1-b)+abs(c1-c);
            mini=min(mini,cost);
        }
        return 0;
    }
    for(ll i=1;i<=4;i++)
    {
        char ch='0'+i;
        rec(s+ch);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b>>c;
    for(ll i=1;i<=n;i++)
    {
        cin>>l[i];
    }
    string s;
    rec(s);
    cout<<mini<<endl;
}
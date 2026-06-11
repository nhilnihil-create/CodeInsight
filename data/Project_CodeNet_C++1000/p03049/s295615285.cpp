#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<string> s(n);
    ll ans=0;
    map<string,int> m;
    rep(i,n)
    {
        cin>>s[i];
        int sn=s[i].length();
        rep(j,sn-1)
        {
            if(s[i][j]=='A' && s[i][j+1]=='B')ans++;
        }
        if(s[i][0]=='B')
        {
            if(s[i][sn-1]=='A')
            {
                m["BA"]++;
            }
            else
            {
                m["BX"]++;
            }
        }
        else
        {
            if(s[i][sn-1]=='A')
            {
                m["XA"]++;
            }
            else
            {
                m["XX"]++;
            }
            
        }
    }
    if(m["XA"]>0 && m["BX"]>0)
    {
        ans+=m["BA"]+1;
        m["XA"]--;
        m["BX"]--;
    }
    else if(m["XA"]>0 || m["BX"]>0)
    {
        ans+=m["BA"];
        if(m["XA"]>0 )m["XA"]--;else m["BX"]--;
    }
    else
    {
        ans+=m["BA"]>0?m["BA"]-1:0;
    }

    ans+=min(m["XA"],m["BX"]);
    cout<<ans;
    

}

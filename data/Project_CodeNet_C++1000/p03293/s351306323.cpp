//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debugg cout<<"debugged\n";
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll ans;
void solve()
{
    string s,t;cin>>s>>t;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==t[0])
        {
            bool flag=0;
            for(int k=0;k<t.size();k++)
            {
                if(s[(k+i)%s.size()]!=t[k])
                    {flag=1;break;}
                //cout<<k<<" ";
            }
            //cout<<endl;
            if(!flag)
            {cout<<"Yes"<<endl;return;}
        }
    }cout<<"No";
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}
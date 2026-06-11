#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<int> c(n);
    vector<int> s(n);
    vector<int> f(n);
    rep(i,n-1)
    {
        cin>>c[i+1]>>s[i+1]>>f[i+1];
    }
    for(int i=1;i<=n-1;i++)
    {
        int now=0;

        now+=s[i];
        now+=c[i];
        if(i==n-1)
        {
            cout<<now<<endl;
            break;
        }
        for(int j=i+1;j<=n-1;j++)
        {
            if(now<=s[j])
            {
                now=s[j];
            }
            else
            {
                int modd=(now-s[j])%f[j];
                now+=modd==0?0:f[j]-modd;
            }
            now+=c[j];
            
        }
        cout<<now<<endl;
    }
    cout<<0<<endl;
}

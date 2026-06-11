#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n)
    {
        cin>>a[i];
    }
    rep(i,n)
    {
        cin>>b[i];
    }

    ll acount=0;
    ll bcount=0;
    rep(i,n)
    {
        ll t=a[i]-b[i];
        if(t==0)continue;
        if(t>0)
        {
            bcount+=t;
        }
        else
        {
            if((-t)%2==0)
            {
                acount+=abs(t)/2;
            }
            else
            {
                bcount+=1;
                acount+=abs(t)/2+1;
            }
            
        }
        
    }
    if(acount>=bcount)
    {
        sayyes;
    }
    else
    {
        sayno;
    }
    
}

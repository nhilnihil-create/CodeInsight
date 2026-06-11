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

    ll n;
    cin>>n;
    ll ans=0;
    ll d=n-1;
    int i=1;
    while(d>=sqrt(n))
    {
        i+=1;
        if(n/d==n%d)
        {
            ans+=d;

        }
        d=(n-1)/i;     
    }
    cout<<ans;
}

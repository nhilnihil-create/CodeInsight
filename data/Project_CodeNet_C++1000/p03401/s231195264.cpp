#include<bits/stdc++.h>
typedef long long ll;
#define dbg          cout<<"Freak"<<endl;
#define dbgg(i)      cout<<i<<endl;
#define N            1e9+7;
#define pb           push_back
using namespace std;
ll t;
ll arr[300005];
vector<ll>v;

int main()
{
    ll a,b,c,d,e,f,g,i,j;
    cin>>t;
    v.pb(0);
    f=0;
    for(i=0;i<t;i++)
    {
        cin>>a;
        v.push_back(a);
        b=abs(a-v[i]);
        f+=b;
    }
    v.pb(0);
    b=abs(0-v[t]);
    f+=b;
    for(i=1;i<=t;i++)
    {
        b=abs(v[i]-v[i-1]);
        c=abs(v[i]-v[i+1]);
        g=f-b-c;
        g=g+abs(v[i+1]-v[i-1]);
        cout<<g<<endl;
    }
    return 0;
}

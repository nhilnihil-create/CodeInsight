#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define line cout<<"----------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll mx=200009;
ll ara[mx]; 
int main()
{
    fast; 
    ll n; 
    cin>>n; 
    set<ll> s; 
    s.insert(-1);
    s.insert(n);
    for(ll i=0;i<n;i++)
    {
        ll x; cin>>x; 
        ara[i]=x; 
        if(x==0) s.insert(i);
    }
    ll ans=0; 
    while((ll)s.size()>1)
    {
        auto it=s.begin();
        auto it1=it; 
        it1++; 
        //cout<<*it<<' '<<*it1<<endl; 
        if(*(it)+1==*it1)
        {
            s.erase(it);
            continue; 
        }
        else
        {
            ll val=200; 
            for(ll i=*(it)+1;i<*(it1);i++)
            {
                val=min(val,ara[i]);
            }
            if(val) ans+=val; 
            for(ll i=*(it)+1;i<*(it1);i++)
            {
                ara[i]-=val; 
                if(ara[i]==0) s.insert(i);
            }
        }
        //line; 
        //for(auto x: s) cout<<x<<' '; 
        //cout<<endl ;
        //line; 
        //cout<<ans<<endl; 
    }
    cout<<ans<<endl; 
    
}

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
ll n; 
ll val[mx],cost[mx]; 
ll maxi=0; 
void call(ll ind, ll sum, ll c)
{
    if(ind==n) 
    {
        maxi=max(maxi,sum-c);
        return ; 
    }
    call(ind+1,sum+val[ind],c+cost[ind]);
    call(ind+1,sum,c);
}
int main()
{
    cin>>n; 
    for(ll i=0;i<n;i++) cin>>val[i]; 
    for(ll i=0;i<n;i++) cin>>cost[i]; 
    call(0,0,0);
    cout<<maxi<<endl; 
}

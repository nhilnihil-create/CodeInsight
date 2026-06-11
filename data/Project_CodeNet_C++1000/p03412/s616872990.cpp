//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define mod 1000000007
#define endl '\n'
typedef long long int ll ;
using namespace std;
#define MAX 100003
ll calculate(ll k, vector<ll> v,vector<ll> temp)
{
    ll val= (1LL<<k+1) ; val--;    // 2^k+1 - 1  
    for(int i=0;i<v.size();i++) v[i]=v[i] & val , temp[i]=temp[i] & val;  //change into k bits
    sort(v.begin(),v.end());   // sum should be max 2 ^ (k+2) -2   and for k th bit set sum should be 2^ k to 2^(k+1)-1 
                                                                        //                2^k + 2^(k+1) to 2 ^ (k+2)-2
    ll x = (1LL<<k);
    ll ans=0;
    ll mx=(1LL<<k+2)-2;
    for(int i=0;i<v.size();i++){
        ll a=temp[i];
        int j=lower_bound(v.begin(),v.end(),x-a)-v.begin();
        int y=upper_bound(v.begin(),v.end(),val-a)-v.begin();
        y--;
        if(j<=y) ans+=(y-j+1);
        j=lower_bound(v.begin(),v.end(),x+val+1-a)-v.begin();
        y=upper_bound(v.begin(),v.end(),mx-a)-v.begin();
        y--;
        if(j<=y) ans+=(y-j+1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin>>n;
    vector<ll> v,temp;
    for(int i=0;i<n;i++) { ll a;  cin>>a ;  temp.push_back(a); }
    for(int i=1;i<=n;i++){
        ll a; cin>>a;
        v.push_back(a);
    }
    ll ans=0;
    for(ll i=0;i<29;i++){
        ll val=calculate(i,v,temp);
        if(val%2==1) ans=ans+(1LL<<i);
    }
    cout<<ans<<endl;
}
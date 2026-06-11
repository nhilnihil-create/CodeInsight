#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n, x;
    cin >> n;
    map<ll, ll>mp;
    for(ll i = 0; i < n; i++){
            //ll x;
       cin >> x;
       mp[x]++;
   // cout << mp[x] << " ";
    }
    //cout<<mp[x]<< " ";
    ll ans = 0;
    for(auto i : mp){
        if(i.second < i.first)
            ans += i.second;
        else
            ans = ans + (i.second - i.first);
    }
    cout << ans << endl;
    return 0;
}

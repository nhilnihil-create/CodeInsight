#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    ll mn=1e9,mx=-1e9;
    ll in,ix;
    for(ll i=0;i<n;i++){
        cin>>ar[i];
        if(ar[i]<mn){
            mn=ar[i];
            in=i;
        }
        if(ar[i]>mx){
            mx=ar[i];
            ix=i;
        }
    }
    if(mx==mn&&mn==0){
        cout<<0<<endl;
        return 0;
    }
    vector<pair<ll,ll>> vp;
    if(abs(mx)>=abs(mn)){
        for(ll i=1;i<n;i++){
            if(ar[i]>=ar[i-1]){
                continue;
            }
            else{
                while(ar[i]<ar[i-1]){
                    ar[i]+=mx;
                    vp.push_back({ix,i});
                    if(ar[i]>mx){
                        mx=ar[i];
                        ix=i;
                    }
                }
            }
        }
    }
    else{
        for(ll i=n-2;i>=0;i--){
            if(ar[i]<=ar[i+1]){
                continue;
            }
            else{
                while(ar[i]>ar[i+1]){
                    ar[i]+=mn;
                    vp.push_back({in,i});
                    if(ar[i]<mn){
                        mn=ar[i];
                        in=i;
                    }
                }
            }
        }
    }
    cout<<vp.size()<<endl;
    for(ll i=0;i<vp.size();i++){
        cout<<vp[i].first+1<<" "<<vp[i].second+1<<endl;
    }
    return 0;
}

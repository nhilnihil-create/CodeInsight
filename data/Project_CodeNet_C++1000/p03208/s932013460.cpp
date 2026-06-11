#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> h(n);
    for(int i = 0;i < n;i++){
        cin>>h[i];
    }
    sort(h.begin(),h.end());
    ll ans=1000000000,now=0;
    for(int i=0;i<n-k+1;i++){
        now=h[i+k-1]-h[i];
        if(now<ans){
            ans=now;
        }
    }
    cout<<ans<<endl;
}
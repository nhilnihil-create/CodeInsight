#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    vector<ll> cnt(3);
    ll n,a,b;cin>>n>>a>>b;
    for(ll i=0;i<n;i++){
        ll p;cin>>p;
        if(p<=a)cnt[0]++;
        else if(p<=b)cnt[1]++;
        else cnt[2]++;
    }
    cout<<(*min_element(cnt.begin(),cnt.end()));
}
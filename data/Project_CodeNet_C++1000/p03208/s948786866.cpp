#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
int main() {
    int n,k;cin>>n>>k;
    vector<ll> h(n);
    rep(i,n) cin>>h[i];
    sort(h.begin(),h.end());
    ll mini=10000000000;
    for(int i=0;i<n-k+1;i++){
        ll dev=h.at(i+k-1)-h.at(i);
        mini=min(mini,dev);
    }
    cout<<mini<<endl;
}
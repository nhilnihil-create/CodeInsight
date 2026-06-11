#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N,M; cin>>N>>M;
    map<ll,ll> mp;
    for (int i = 0; i < N; i++){
        ll K; cin>>K;
        vector<ll> A(K);
        for(ll j=0;j<K;j++){
            cin>>A[j];
            mp[A[j]]++;
        }
    }
    ll ans=0;
    for (int i = 1; i <= M; i++){
        if(mp[i]==N) ans++;
    }
    cout<<ans<<endl;
}

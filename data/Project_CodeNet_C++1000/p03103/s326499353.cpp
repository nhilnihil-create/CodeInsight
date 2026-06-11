#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N, M;
    cin>>N>>M;

    vector<pair<ll, ll>> v(N);
    for(int i=0; i<N; i++){
        ll a, b;
        cin>>a>>b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    for(int i=0; i<N; i++){
        if(M>=v[i].second){
            ans += v[i].first*v[i].second;
            M -= v[i].second;
        }else{
            ans += v[i].first*M;
            M = 0;
        }
        if(M == 0){
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}
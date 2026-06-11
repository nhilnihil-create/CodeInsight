#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,K;
    cin >> N >>K;
    ll sum[N+1] ={};
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        sum[i+1] = sum[i]+a;
    }
    vector<ll> candidates;
    for(int l=0;l<N;l++)for(int r =l;r<N;r++){
        candidates.push_back(sum[r+1]-sum[l]);
    }
    vector<ll> used(candidates.size(),false);
    ll ans =0;
    for(ll degree = 50;degree>=0;--degree){
        ll num =0;
        for(int i=0;i<candidates.size();i++){
            if(used[i]){
                continue;
            }
            if(candidates[i] & (1ll<<degree)){
                num++;
            }
        }
        if(num>=K){
            ans += (1ll<<degree);
            for(int i=0;i<candidates.size();i++){
                if(!(candidates[i] & (1ll<<degree))){
                    used[i] = true;
                } 
            }
        }
    }
    cout << ans << endl;
    return 0;
}
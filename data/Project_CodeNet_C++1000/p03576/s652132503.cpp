#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using ll = long long;

using namespace std;

signed main() {
    int N, K;cin >> N >> K;
    vector<pair<ll, ll>> v1, v2;
    for(int i = 0;i < N;i++){
        ll a, b;cin >> a >> b;
        v1.push_back({a, b});
        v2.push_back({b, a});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll ans = 1e18 * 5;
    for(int i = 0;i < N;i++){
        for(int j = i + 1;j < N;j++){
            for(int k = 0;k < N;k++){
                int cnt = 0;
                int l;
                for(l = k;l < N;l++){
                    pair<ll, ll> w = v2[l];
                    if(v1[i].first <=  w.second && w.second <= v1[j].first){
                        cnt++;
                    }
                    if(cnt == K)break;
                }
                //cout<<cnt<<endl;
                if(cnt == K)ans = min(ans, (v1[j].first - v1[i].first) *  abs(v2[l].first - v2[k].first));
            }
        }
    }
    cout<<ans<<endl;
}



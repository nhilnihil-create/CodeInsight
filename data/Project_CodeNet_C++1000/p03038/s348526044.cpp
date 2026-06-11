#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

#define int long long
using namespace std;

std::vector<int> PrimeFactoring(int N){
    std::vector<int> ans;
    while(N != 1){
        for(int a = 2;a <= N;a++){
            if(N % a == 0){
                N /= a;
                ans.push_back(a);
                break;
            }
        }
    }
    return ans;
}

signed main() {
    int N, M;cin >> N >> M;
    map<int, int> mp;
    for(int i = 0;i < N;i++){
        int a;cin >> a;
        mp[a]++;
    }
    for(int i = 0;i < M;i++){
        int a, b;cin >> a >> b;
        mp[b] += a;
    }
    vector<pair<int, int>> v;
    for(auto a : mp)v.push_back(a);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    int cnt = 0;
    for(int i = 0;i < v.size();i++){
        if(cnt + v[i].second > N){
            ans += v[i].first * (N - cnt);
            break;
        }else{
            cnt += v[i].second;
            ans += v[i].second * v[i].first;
        }
    }
    cout<<ans<<endl;
}



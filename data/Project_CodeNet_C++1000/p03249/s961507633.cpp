// ※※※ 解答不能 ※※※
// 解き直し.
// tourist氏.
// https://atcoder.jp/contests/arc103/submissions/3296203
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){

    int N;
    scanf("%d", &N);
    vector<LL> d(N);
    vector<int> weight(N, 1);
    map<LL, int> mp;
    for(int i = 0; i < N; i++){
        scanf("%lld", &d[i]);
        mp[d[i]] = i;
    }
    
    vector<pair<int, int>> res;
    for(int itt = 0; itt < N - 1; itt++){
        auto it = mp.rbegin();
        int i = it->second;
        LL want = d[i] - (N - weight[i]) + weight[i];
        if(mp.find(want) == mp.end() || mp[want] == i){
            printf("%d\n", -1);
            return 0;
        }
        int j = mp[want];
        res.emplace_back(i, j);
        weight[j] += weight[i];
        mp.erase(--mp.end());
    }
    
    vector<LL> real_dist(N, -1);
    real_dist[0] = 0;
    vector<vector<int>> g(N);
    for(auto &p : res){
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }
    
    vector<int> que(1, 0);
    for(int b = 0; b < (int)que.size(); b++){
        for(int j : g[que[b]]){
            if(real_dist[j] == -1){
                que.push_back(j);
                real_dist[j] = real_dist[que[b]] + 1;
            }
        }
    }
    if(accumulate(real_dist.begin(), real_dist.end(), 0LL) != d[0]){
        printf("%d\n", -1);
        return 0;
    }
    
    for(auto &p : res) printf("%d %d\n", p.first + 1, p.second + 1);

    return 0;

}
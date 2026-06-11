#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int n;
    cin >> n;
    if(n == 3){
        cout << "2 5 63\n";
        return 0;
    }

    // 総和が6の倍数
    // 2, 3, 4, 9
    vector<vector<int>> v(6);
    vector<int> ans = {2, 3, 4, 9};
    for(int i = 5; i <= 30000; ++i){
        if(i == 9)
            continue;
        if(i % 2 == 0 || i % 3 == 0)
            v[i % 6].emplace_back(i);
    }
    while(ans.size() < n){
        int nok = n - ans.size();
        if(nok >= 2 && !v[2].empty()){
            ans.emplace_back(v[2].back());
            ans.emplace_back(v[4].back());
            v[2].pop_back();
            v[4].pop_back();
        }else if(nok >= 2 && v[3].size() >= 2){
            ans.emplace_back(v[3].back());
            v[3].pop_back();
            ans.emplace_back(v[3].back());
            v[3].pop_back();
        }else{
            ans.emplace_back(v[0].back());
            v[0].pop_back();
        }
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}

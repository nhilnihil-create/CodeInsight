#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(auto& x : a)
        cin >> x;
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    // [t, INF)の中でq個選ぶ
    auto f = [&](int t){
        vector<vector<int>> v(1, vector<int>(0));
        for(auto& x : a){
            if(x >= t)
                v.back().emplace_back(x);
            else if(!v.back().empty())
                v.emplace_back(0);
        }
        if(v.back().empty())
            v.pop_back();

        for(auto& w : v){
            w.emplace_back(0);
            sort(w.begin(), w.end());
            w.resize(max(0, (int)w.size() - k + 1));
            if(w.empty())
                w.emplace_back(0);
        }
        vector<int> dp(1, 0);
        int ns = 0;
        for(auto& w : v){
            int ne = ns + w.size() - 1;
            vector<int> nex(ne + 1, 2 * MOD);
            for(int i = 0; i <= ns; ++i)
                for(int j = 0; j < w.size(); ++j)
                    nex[i + j] = min(nex[i + j], max(dp[i], w[j]));
            ns = ne;
            dp = move(nex);
        }
        int ret = ns < q ? 2 * MOD : dp[q];
        return ret;
    };

    int ans = MOD;
    for(auto& x : b)
        ans = min(ans, f(x) - x);
    cout << ans << endl;
}

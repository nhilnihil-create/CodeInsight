#include <bits/stdc++.h>
using namespace std;
#define int long long

struct flower {
    int ht, bty;
};

int solve(vector<flower>& vec, int N) {
    map<int, int> meaningful;
    int dp[N], ans = vec[0].bty;
    dp[0] = vec[0].bty;
    meaningful[vec[0].ht] = dp[0];

    for(int i=1; i<N; i++) {
        dp[i] = vec[i].bty;
        auto it = meaningful.lower_bound(vec[i].ht + 1);
        if(it != meaningful.begin()) {
            it--;
            dp[i]+= it->second;
        }
        meaningful[vec[i].ht] = dp[i];
        it = meaningful.upper_bound(vec[i].ht);
        while(it != meaningful.end() && it->second <= dp[i]) {
            auto tmp = it;
            tmp++;
            meaningful.erase(it);
            it = tmp;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int32_t main() {
    int N; cin>>N;
    vector<flower> vec(N);
    for(int i=0; i<N; i++) cin>>vec[i].ht;
    for(int i=0; i<N; i++) cin>>vec[i].bty;

    cout<<solve(vec, N)<<endl;
    return 0;
}

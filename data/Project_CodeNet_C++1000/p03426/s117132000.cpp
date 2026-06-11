#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int H, W, D; cin >> H >> W >> D;
    vector<vector<int>> a(H, vector<int>(W));
    vector<pair<int, int>> b(H * W + 1);//逆引き用
    rep(i, H)rep(j, W){
        int num;
        cin >> num;
        b[num] = make_pair(i, j);
        a[i][j] = num;
    }
    // rep(i, H * W){
    //     cout << i + 1 << endl;
    //     cout << b[i + 1].first << "," << b[i + 1].second<<endl;
    // }
    vector<vector<int>> cost(D + 1);
    for(int i = 1; i <= D; i++){
        int k = 1;
        cost[i].push_back(0);
        while(i + k * D <= H * W){
            cost[i].push_back(abs(b[i + k * D].first - b[i + (k - 1) * D].first) + abs(b[i + k * D].second - b[i + (k - 1) * D].second) + cost[i][k - 1]);
            k++;
        }
    }

    // rep(i, D + 1){
    //     rep(j, cost[i].size())cout << cost[i][j] << " ";
    //     cout << endl;
    // }

    int Q;
    cin >> Q;
    vector<int> ans;
    rep(i, Q){
        int L, R; cin >> L >> R;
        int t = L % D;
        if(t == 0) t = D;
        R -= D;
        L -= D;
        ans.push_back(cost[t][(R + (D - 1)) / D] - cost[t][(L + (D - 1)) / D]);
    }
    rep(i, Q)cout << ans[i] << endl;
}

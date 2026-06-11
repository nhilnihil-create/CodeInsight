#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> trains(N, vector<int>(N, 0)), sum(N + 1, vector<int>(N + 1, 0));
    rep(i, M){
        int l, r; cin >> l >> r;
        l--;
        r--;
        trains[l][r]++;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + trains[i][j];
        }
    }

    vector<int> ans;
    rep(i, Q){
        int l, r; cin >> l >> r;l--;
        int tmp = sum[r][r] - sum[l][r] - sum[r][l] + sum[l][l];
        ans.push_back(tmp);
    }

    // rep(i, N + 1){
    //     rep(j, N + 1)cout << sum[i][j] << " ";
    //     cout << endl;
    // }
    rep(i, Q)cout << ans[i] << endl;

}
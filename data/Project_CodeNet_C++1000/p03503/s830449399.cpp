#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)


int main(){
    int n;
    cin >> n;
    vector<vector<int>> open;
    rep(i, n){
        vector<int> tmp(10);
        rep(j, 10) cin >> tmp[j];
        open.push_back(tmp);
    }
    vector<vector<int>> profit;
    rep(i, n){
        vector<int> tmp(11);
        rep(j, 11) cin >> tmp[j];
        profit.push_back(tmp);
    }
    int ans = -1000000000;
    for (int bit = 0; bit < (1<<10); bit++){
        if (bit == 0) continue;
        int score = 0;
        rep(i, n){
            int cnt = 0;
            rep(j, 11) if (bit & (1<<j) && open[i][j]) cnt++;
            score += profit[i][cnt]; 
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
}  

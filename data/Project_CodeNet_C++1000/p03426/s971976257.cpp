#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int main () {
    int H, W, D; cin >> H >> W >> D;
    vector<vector<int>> a(H, vector<int>(W));
    vector<pair<int, int>> b(H * W + 1);//逆引き用
    rep(i, H)rep(j, W){
        int num;
        cin >> num;
        b[num] = make_pair(i, j);
        a[i][j] = num;
    }

    vector<vector<int>> cost(D + 1);
    for(int i = 1; i <= D; i++){
        int k = 1;
        cost[i].push_back(0);
        while(i + k * D <= H * W){
            cost[i].push_back(abs(b[i + k * D].first - b[i + (k - 1) * D].first) + abs(b[i + k * D].second - b[i + (k - 1) * D].second) + cost[i][k - 1]);
            k++;
        }
    }

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
    return 0 ;
}

 

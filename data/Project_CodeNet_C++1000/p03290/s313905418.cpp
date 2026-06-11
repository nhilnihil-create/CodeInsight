#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

vector<vector<bool>> TFcombination(int n){
    vector<vector<bool>> ans(pow(2, n), vector<bool>(n));
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            ans[i][j] = i >> j & 1;
        }
    }
    return ans;
}

int main(){
    int d, g;
    cin >> d >> g;
    vector<ll> p(d), c(d);
    for(int i = 0; i < d; i++){
        cin >> p[i] >> c[i];
    }

    vector<vector<bool>> isPerfect = TFcombination(d);
    int ans = 1e9;
    for(auto x : isPerfect){
        int score = 0;
        int tmpans = 0;
        int remainNumMax;
        rep(i, d){
            if(x[i]){
                score += (100 * (i + 1) * p[i] + c[i]);
                tmpans += p[i];
            }
            else{
                remainNumMax = i;
            }
        }
        if(score < g){
            for(int i = 0; i < p[remainNumMax]; i++){
                score += 100 * (remainNumMax + 1);
                tmpans++;
                if(score >= g){
                    // ans = min(ans, tmpans);
                    break;
                }
            }
        }
        // ans = min(ans, tmpans);
        if(score >= g){
            ans = min(ans, tmpans);
        }
    }

    cout << ans << endl;
    return 0;
}
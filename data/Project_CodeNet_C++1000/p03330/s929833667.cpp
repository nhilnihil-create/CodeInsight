#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

int solve(map<int, int> map, const vector<vector<int>> &vec, int nc){
    int ret = 0;
    for(auto p : map){
        int color = p.first;
        int num = p.second;
        ret += num * vec[color][nc];
    }
    return ret;
}

int main(){
    int n, c; cin >> n >> c;
    vector<vector<int>> cost(c, vector<int>(c)), mp(n, vector<int>(n));
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            cin >> cost[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mp[i][j];
            mp[i][j]--;
        }
    }
    map<int, int> mp1, mp2, mp0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i + j) % 3 == 0){
                mp0[mp[i][j]]++;
            }
            if((i + j) % 3 == 1){
                mp1[mp[i][j]]++;
            }
            if((i + j) % 3 == 2){
                mp2[mp[i][j]]++;
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < c; k++){
                if(i == j || j == k || k == i) continue;
                int tmp = 0;
                tmp += solve(mp0, cost, i);
                tmp += solve(mp1, cost, j);
                tmp += solve(mp2, cost, k);
                //cout << i << ", " << j << ", " << k << ", " << tmp << endl;
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}
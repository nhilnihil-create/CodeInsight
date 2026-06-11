#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool x_dp[4010][16100] = {};
bool y_dp[4010][16100] = {};
int ori = 8050;

int main(){
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<int> h, v;
    int cnt = 0;
    bool m = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'F') cnt++;
        else{
            if(m){
                if(cnt != 0) h.emplace_back(cnt);
                m = false; cnt = 0;
            }else{
                if(cnt != 0) v.emplace_back(cnt);
                m = true; cnt = 0;
            }
        }
    }
    if(m){
        if(cnt > 0) h.emplace_back(cnt);
    }else{
        if(cnt > 0) v.emplace_back(cnt);
    }
    if(s[0] == 'F'){
        x_dp[1][ori + h[0]] = true;
    }else{
        if(h.size() > 0){
            x_dp[1][ori + h[0]] = true;
            x_dp[1][ori - h[0]] = true;
        }else{
            x_dp[0][ori] = true;
        }
    }
    y_dp[0][ori] = true;
    for(int i = 1; i < h.size(); i++){
        for(int j = ori - s.size(); j <= ori + s.size(); j++){
            if(x_dp[i][j]){
                x_dp[i + 1][j - h[i]] = true;
                x_dp[i + 1][j + h[i]] = true;
            }
        }
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = ori - s.size(); j <= ori + s.size(); j++){
            if(y_dp[i][j]){
                y_dp[i + 1][j - v[i]] = true;
                y_dp[i + 1][j + v[i]] = true;
            }
        }
    }
    if(x_dp[h.size()][ori + x] && y_dp[v.size()][ori + y]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

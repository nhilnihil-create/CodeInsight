#include <bits/stdc++.h>
using namespace std;

int main(){
    int L;
    cin >> L;
    int S = 1, T = 20;
    vector<vector<int>> ans;
    while(L > 1){
        if(L%2){
            ans.push_back({S, T, L-1});
            L--;
        }else{
            ans.push_back({S, S+1, 0});
            ans.push_back({S, S+1, L/2});
            S++;
            L /= 2;
        }
    }
    cout << S << " " << ans.size() << endl;
    for(auto& v : ans){
        cout << v[0] << " " << (v[1] == T ? S : v[1]) << " " << v[2] << endl;
    }
}
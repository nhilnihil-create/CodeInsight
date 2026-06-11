#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m,ans =0;
    cin >> n >> m;
    vector<vector<int>> data(n*m, vector<int>(n*m));
    vector<int> like(m*n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i).at(0);
        for (int j = 0; j < data.at(i).at(0); j++){
            cin >> data.at(i).at(j+1);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < data.at(i).at(0); j++){
            like.at(data.at(i).at(j+1)-1) ++;
        }
    }
    for (int i = 0; i < m; i++){
        if(like.at(i) == n) ans++;
    }
    cout << ans << endl;
}
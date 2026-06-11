#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,c,ans = 0;
    cin >> n >> m >> c;
    vector<int> data_b(m);
    vector<vector<int>> data_a(n, vector<int>(m));
    for (int i = 0; i < m; i++){
        cin >> data_b.at(i);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> data_a.at(i).at(j);
        }
    }
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < m; j++){
            sum += data_a.at(i).at(j) * data_b.at(j);
        }
        if(sum + c > 0)ans ++;
    }
    cout << ans << endl;
}
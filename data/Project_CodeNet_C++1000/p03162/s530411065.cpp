#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    int n; cin >> n;

    vector<vector<int>>a(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    
    vector<vector<int>>happy(n, vector<int>(3));
    happy[n-1][0] = a[n-1][0];
    happy[n-1][1] = a[n-1][1];
    happy[n-1][2] = a[n-1][2];
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < 3; j++){
            happy[i][j] = max(happy[i+1][(j+1)%3] + a[i][j], happy[i+1][(j+2)%3]+a[i][j]);
        }
    }

    cout<<max({happy[0][0], happy[0][1], happy[0][2]})<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, c, count=0; cin >> n >> m >> c;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<m;j++) sum += b[j]*a[i][j];
        sum += c;
        if(sum > 0) count++;
    }
    cout << count << endl;
    return 0;
}


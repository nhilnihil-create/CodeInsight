#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<vector<int>> a(3, vector<int>(3, 0));
    rep(i,3) rep(j,3) cin >> a[i][j];

    rep(i,2){
        int d = a[0][i] - a[0][i+1];
        if(d != a[1][i] - a[1][i+1] || d!= a[2][i]-a[2][i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,2){
        int d = a[i][0] - a[i+1][0];
        if(d != a[i][1] - a[i+1][1] || d!= a[i][2]-a[i+1][2]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
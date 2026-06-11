#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
    int total = 0;
    vector<vector<int>> a(3, vector<int>(3));
    rep(i, 3){
        rep(j, 3){
            cin >> a[i][j];
            total+=a[i][j];
        }
    }
    int c = a[0][0] + a[1][1] + a[2][2];
    if(c * 2 == total - c){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
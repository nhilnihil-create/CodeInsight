/**
 *    author:  FromDihPout
 *    created: 2020-08-16
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const int N = 3;
    vector<vector<int>> a(N, vector<int> (N));
    vector<int> mins(N, 500);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            mins[i] = min(mins[i], a[i][j]);
        }
    }
    
    vector<int> b(N);
    for (int j = 0; j < N; j++) {
        b[j] = a[0][j] - mins[0];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] - mins[i] != b[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
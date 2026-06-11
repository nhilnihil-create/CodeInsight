#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> a(2,vector<int>(N));
    for (int i = 0; i < N; i++) {
        cin >> a.at(0).at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> a.at(1).at(i);
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        int candy = 0;
        for (int j = 0; j < N; j++) {
            if (j <= i) {
                candy += a.at(0).at(j);
            }
            if (j >= i) {
                candy += a.at(1).at(j);
            }
        }
        if (max < candy) {
            max = candy;
        }
    }

    cout << max << endl;

}
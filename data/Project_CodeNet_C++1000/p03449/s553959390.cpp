#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(2, vector<int>(N));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int max_candies = 0;

    for (int i = 0; i < N; i++) {
        int candies = 0;
        int line = 0;
        for (int j = 0; j < N; j++) {
            
            candies += a[line][j];
            //cout << "at " << line << ", " << j << ", candies " << candies << endl;
            if (i == j) {
                line++;
                candies += a[line][j];
                //cout << "at " << line << ", " << j << ", candies " << candies << endl;
            }
        }
        max_candies = max(candies, max_candies);
    }
    cout << max_candies << endl;

    return 0;
}
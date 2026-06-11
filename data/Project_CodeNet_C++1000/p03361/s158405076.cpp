#include <iostream>
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    string s;
    int grid[h+2][w+2] = {};
    for (int i=0; i<h; i++) {
        cin >> s;
        for (int j=0; j<w; j++) {
            if (s[j] == '#') grid[i+1][j+1]++;
        }
    }
    int sum;
    for (int i=1; i<h+1; i++) {
        for (int j=1; j<w+1; j++) {
            if (grid[i][j] == 1) {
                sum = grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1];
                if (sum == 0) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}
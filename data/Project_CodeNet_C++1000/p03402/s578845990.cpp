#include<iostream>
using namespace std;

char grid[101][101];

int main() {
    int A, B;
    cin >> A >> B;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) grid[i][j] = '.';
    }
    cout << 100 << ' ' << 100 << endl;
    int row = 0, col = 0;
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == 1 && k == 1) grid[row + j][col + k] = '.';
                else grid[row + j][col + k] = '#';
            }
        }
        col += 4;
        if (col == 100) {
            row += 4;
            col = 0;
        }
    }
    if (A - 1 < B) {
        row = 1, col = 1;
        for (int i = 0; i < B - A + 1; i++) {
            grid[row][col] = '#';
            col += 4;
            if (col >= 99) {
                row += 4;
                col = 1;
            }
        }
    }
    else if (A - 1 > B) {
        if (col == 0) row -= 4;
        row += 3, col = 0;
        grid[row][col] = '#';
        row++;
        for (int i = 0; i < 99; i++) grid[row][i] = '#';
        row++;
        for (int i = 0; i < A - B - 1; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == 0 && k == 1) continue;
                    grid[row + j][col + k] = '#';
                }
            }
            col += 3;
            if (col >= 99) {
                row += 2;
                col = 0;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) cout << grid[i][j];
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<char>> vec(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> vec[i][j];
        }
    }
    printf("%c%c%c\n", vec[0][0], vec[1][1], vec[2][2]);
}
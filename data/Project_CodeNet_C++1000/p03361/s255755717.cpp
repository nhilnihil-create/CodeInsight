#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> data(H,vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> data.at(i).at(j);
        }
    }

    bool a = true;

    for (int i = 0; i < H; i++) {
        if (a == false) {
            break;
        }
        for (int j = 0; j < W; j++) {
            if (data.at(i).at(j) == '#') {
                if (i == 0) {
                    if (j == 0) {
                        if (data.at(0).at(1) == '.' && data.at(1).at(0) == '.') {
                            a = false;
                            break;
                        }
                    }
                    if (1 <= j && j < W - 1) {
                        if (data.at(0).at(j - 1) == '.' && data.at(0).at(j + 1) == '.' && data.at(1).at(j) == '.') {
                            a = false;
                            break;
                        }
                    }
                    if (j == W - 1) {
                        if (data.at(0).at(W - 2) == '.' && data.at(1).at(W - 1) == '.') {
                            a = false;
                            break;
                        }
                    }
                }
                if (1 <= i && i < H - 1) {
                    if (j == 0) {
                        if (data.at(i).at(1) == '.' && data.at(i - 1).at(0) == '.' && data.at(i + 1).at(0) == '.') {
                            a = false;
                            break;
                        }
                    }
                    if (1 <= j && j < W - 1) {
                        if (data.at(i).at(j - 1) == '.' && data.at(i).at(j + 1) == '.' && data.at(i - 1).at(j) == '.' && data.at(i + 1).at(j) == '.') {
                            a = false;
                            break;
                        }
                    }
                    if (j == W - 1) {
                        if (data.at(i).at(W - 2) == '.' && data.at(i - 1).at(W - 1) == '.' && data.at(i + 1).at(W - 1) == '.') {
                            a = false;
                            break;
                        }
                    }
                }
                if (i == H - 1) {
                    if (j == 0) {
                        if (data.at(H - 1).at(1) == '.' && data.at(H - 2).at(0) == '.') {
                            a = false;
                            break;
                        }
                    }
                    if (1 <= j && j < W - 1) {
                        if (data.at(H - 1).at(j - 1) == '.' && data.at(H - 1).at(j + 1) == '.' && data.at(H - 2).at(j) == '.') {
                            a = false;
                            break;
                        }
                    }
                    if (j == W - 1) {
                        if (data.at(H - 1).at(W - 2) == '.' && data.at(H - 2).at(W - 1) == '.') {
                            a = false;
                            break;
                        }
                    }
                }
            }
        }
    }

    if (a == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
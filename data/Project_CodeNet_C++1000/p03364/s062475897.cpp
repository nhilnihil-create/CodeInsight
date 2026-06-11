#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        bool check = true;
        vector<vector<char>> sub(N, vector<char>(N));
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                sub[x][y] = s[x][(y + i) % N];
            }
        }
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (sub[x][y] != sub[y][x]) check = false;
            }
        }
        if (check) sum += (N - i);
    }
    for (int i = 1; i < N; i++) {
        bool check = true;
        vector<vector<char>> sub(N, vector<char>(N));
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                sub[x][y] = s[(x + i) % N][y];
            }
        }
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (sub[x][y] != sub[y][x]) check = false;
            }
        }
        if (check) sum += (N - i);
    }
    cout << sum << endl;
}
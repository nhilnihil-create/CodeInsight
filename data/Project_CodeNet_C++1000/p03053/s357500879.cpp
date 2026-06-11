#include "bits/stdc++.h"

using namespace std;

void Main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int> > A(H, vector<int>(W, 0));
    int nbBlack = 0;
    queue<pair<int, int> > nextQue;
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j) {
            if (s[j] == '#') {
                A[i][j] = 1;
                ++nbBlack;
                nextQue.push(make_pair(i, j));
            }
            else {
                A[i][j] = 0;
            }
        }
    }

    int ans = 0;
    while (nbBlack < H * W) {
        ++ans;
        queue<pair<int, int> > que = nextQue;
        queue<pair<int, int> >().swap(nextQue);
        while (!que.empty()) {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            if (i < H - 1 && A[i + 1][j] == 0) {
                nextQue.push(make_pair(i + 1, j));
                A[i + 1][j] = 1;
                ++nbBlack;
            }
            if (i > 0 && A[i - 1][j] == 0) {
                nextQue.push(make_pair(i - 1, j));
                A[i - 1][j] = 1;
                ++nbBlack;
            }
            if (j < W - 1 && A[i][j + 1] == 0) {
                nextQue.push(make_pair(i, j + 1));
                A[i][j + 1] = 1;
                ++nbBlack;
            }
            if (j > 0 && A[i][j - 1] == 0) {
                nextQue.push(make_pair(i, j - 1));
                A[i][j - 1] = 1;
                ++nbBlack;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

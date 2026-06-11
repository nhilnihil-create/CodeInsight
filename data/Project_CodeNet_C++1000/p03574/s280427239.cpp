#include <bits/stdc++.h>
using namespace std;

int counter(vector<string> s, int i, int j, int W) {
    int count = 0;
    if (j > 0)
        if (s[i][j - 1] == '#') count++;
    
    if (s[i][j] == '#') count++;

    if (j < W - 1)
        if (s[i][j + 1] == '#') count++;
    
    return count;
}


int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S[i].size(); j++) {
            int count = 0;
            if (S[i][j] == '#') continue;
            if (i > 0)
                count += counter(S, i - 1, j, W);
            count += counter(S, i, j, W);
            if (i < H - 1)
                count += counter(S, i + 1, j, W);
            S[i][j] = count + (int)'0';
        }
    }
    for (string s : S)
        cout << s << endl;
}
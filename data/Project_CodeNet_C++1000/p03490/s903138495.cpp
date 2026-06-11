#include <bits/stdc++.h>
using namespace std;
bool dpX[8000][16100] = {};
bool dpY[8000][16100] = {};

#define OFFSET 8000
#define MAX_S 8000

int main() {
    string S;
    cin >> S;
    int x, y;
    cin >> x >> y;

    vector<int> a;
    int cnt = 0;
    for(int i=0; i < S.size(); ++i) {
        if(S[i] == 'F') {
            ++cnt;
            if(i+1 == S.size()) a.push_back(cnt);
        } else {
            a.push_back(cnt);
            cnt = 0;
        }
    }

    int n = a.size();
    if(n == 1) {
        if(x == a[0] && y == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    dpX[0][a[0] + OFFSET] = true;
    for(int i=2; i<n; i += 2) {
        for(int j=-MAX_S; j<=MAX_S; ++j) {
            if(j - a[i] >= -MAX_S) dpX[i][j + OFFSET] |= dpX[i-2][j - a[i] + OFFSET];
            if(j + a[i] <= MAX_S) dpX[i][j + OFFSET] |= dpX[i-2][j + a[i] + OFFSET];
        }
    }

    dpY[1][a[1] + OFFSET] = true;
    dpY[1][(-1) * a[1] + OFFSET] = true;
    for(int i=3; i<n; i += 2) {
        for(int j=-MAX_S; j<=MAX_S; ++j) {
            if(j - a[i] + OFFSET >= 0) dpY[i][j + OFFSET] |= dpY[i-2][j - a[i] + OFFSET];
            if(j + a[i] <= MAX_S) dpY[i][j + OFFSET] |= dpY[i-2][j + a[i] + OFFSET];
        }
    }

    if(n % 2) {
        if(dpX[n-1][x + OFFSET] && dpY[n - 2][y + OFFSET]) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        if(dpX[n-2][x + OFFSET] && dpY[n - 1][y + OFFSET]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
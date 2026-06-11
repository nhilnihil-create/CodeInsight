#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


string S;


void input() {
    cin >> S;
}


int main() {
    input();
    int n = S.size();
    vector<int> w(3, 0);
    for (char c : S) w[c - 'a']++;
    int x = 0;
    rep(i, 3) {
        for (int j = i + 1; j < 3; j++) {
            x = max(x, max(w[i] - w[j], w[j] - w[i]));
        }
    }
    if (x < 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

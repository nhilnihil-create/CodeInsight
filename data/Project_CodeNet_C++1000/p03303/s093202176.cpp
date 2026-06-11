#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    string S;
    int w;
    cin >> S >> w;
    for (int i = 0; i < S.size(); i += w) {
        cout << S[i];
    }
    cout << "\n";
}
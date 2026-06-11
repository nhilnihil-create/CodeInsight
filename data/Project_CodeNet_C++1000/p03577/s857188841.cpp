#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    for (int i = 0; i < S.size() - 8; ++i) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}

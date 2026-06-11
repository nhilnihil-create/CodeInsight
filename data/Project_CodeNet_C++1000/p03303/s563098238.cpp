#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    int w;
    cin >> S >> w;
    for (int i = 0; i < S.length(); i += w) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}
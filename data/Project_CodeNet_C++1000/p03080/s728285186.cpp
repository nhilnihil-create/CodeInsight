#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int r = 0;
    for (int i = 0; i < N; i++) {
        r += s[i] == 'R' ? 1 : 0;
    }
    cout << (r > N - r ? "Yes" : "No") << endl;
    return 0;
}
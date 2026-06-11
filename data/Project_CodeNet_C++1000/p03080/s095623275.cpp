#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (char c: s) {
        if (c == 'R') cnt++;
    }
    int b = n - cnt;
    bool ans = (cnt > b);
    cout << (ans ? "Yes" : "No") << endl;
}
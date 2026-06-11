#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    set<string> dic;
    for (int i = 1; i <= k; i++) {
        rep(j, n-i+1) {
            // char c[i];
            string c;
            rep(l, i) {
                // c[l] = s[j+l];
                c.push_back(s[j+l]);
            }
            dic.insert(c);
        }
    }
    int i = 0;
    for (string p : dic) {
        i++;
        if (i == k) {
            cout << p << endl;
        }
    }
}
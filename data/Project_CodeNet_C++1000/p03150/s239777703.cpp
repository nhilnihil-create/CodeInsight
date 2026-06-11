#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        string left = s.substr(0, i);
        for (int j = 0; j < n - i; j++) {
            string res = left + s.substr(i + j);
            if ("keyence" == res) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
}
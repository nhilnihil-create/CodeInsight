#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    string t("keyence");
    int j = 0;
    bool once = true;

    for (int i = 0; i < s.size()-1; i++) {
        for (int j = i; j < s.size(); j++) {
            string t = s.substr(0, i) + s.substr(j);
            if (t == "keyence") {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
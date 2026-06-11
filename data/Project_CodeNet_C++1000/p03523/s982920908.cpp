#include <bits/stdc++.h>
using namespace std;
int main () {
    string x[] = {"KIH", "B", "R", ""};
    string s;
    cin >> s;
    for (int i = 0; i < (1 << 4); i++) {
        string res = "";
        for (int j = 0; j < 4; j++) {
            if ((1 << j) & i) {
                res += "A";
            }
            res += x[j];
        }
        if (s == res) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
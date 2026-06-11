#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int A, B;
    cin >> A >> B;
    string s;
    cin >> s;

    size_t pos = s.find('-');
    bool ok(true);
    if (pos == A) {
        if (s.size() == A + B + 1) {
            for (int i = 0; i < s.size(); i++) {
                if (i == A) continue;
                if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                } else {
                    ok = false;
                    break;
                }
            }
        } else {
            ok = false;
        }
    } else {
        ok = false;
    }
    cout << ((ok) ? "Yes" : "No") << endl;
    
    return 0;
}

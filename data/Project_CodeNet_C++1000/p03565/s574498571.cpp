#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    string s, t;
    cin >> s >> t;

    int n = s.size() - 1;
    int m = t.size() - 1;
    bool ok = false;
    int cnt = 0;
    for (int i = n; i >= m; i--) {
        ok = true;
        for (int j = 0; j <= m; j++) {
            if(s[i - j] != t[m - j] && s[i - j] != '?') ok = false;
        }
        if (ok) {
            for (int j = 0; j <= m; j++) {
                s[i - j] = t[m - j];
            }
            break;
        }
    }

    if (ok) {
        for (int i = 0; i <= n; i++) {
            if (s[i] == '?') cout << 'a';
            else cout << s[i];
        }
        cout << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
}
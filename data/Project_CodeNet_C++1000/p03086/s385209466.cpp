#include <iostream>
#include <string>

using namespace std;

bool check(char c) {
    return (c == 'A' || c == 'T'|| c == 'C' || c == 'G');
}

int main() {
    string s;   cin >> s;
    int l = s.length(), ans = 0;

    for (int i = 0; i < l; i++) {
        int j = i, tmp = 0;
        while (j < l && s[j] && check(s[j])) {
            tmp++;
            j++;
        }

        ans = max(tmp, ans);
    }

    cout << ans << endl;
    return 0;
}
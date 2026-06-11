#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;   int n, ans = 0, a = 0, b = 0, ab = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int l = s.length();
        if (s[0] == 'B' && s[l-1] == 'A')
            ab++;
        else if (s[0] == 'B')
            b++;
        else if (s[l-1] == 'A')
            a++;

        for (int j = 0; j < l-1; j++) {
            if (s[j] == 'A' && s[j+1] == 'B')
                ans++;
        }
    }

    if (a > 0) {
        cout << ans + ab + min(a, b) << endl;
        return 0;
    }
    else if (ab > 0){
        cout << ans + ab-1 + ((b > 0)?1:0) << endl;
        return 0;
    }
    else {
        cout << ans << endl;
        return 0;
    }
}
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    s = "0" + s;

    if(s == string(s.rbegin(), s.rend()) && s[1] == '1') {
        int r = 1;
        for(int i=2; i<s.size(); i++) {
            cout << r << ' ' << i << endl;
            if(s[i-1] == '1') r = i;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}

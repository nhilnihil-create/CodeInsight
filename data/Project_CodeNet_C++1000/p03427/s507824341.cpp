#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool corner = true;
    for (int i=1; i<s.size(); ++i) {
        if (s[i] != '9') corner = false;
    }
    int ans;
    if (corner) {
        ans = (s[0] - '0') + (s.size()-1)*9;
    } else {
        ans = (s[0] - '0' - 1) + (s.size()-1)*9;
    }
    cout << ans << endl;
}
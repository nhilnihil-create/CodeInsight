#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int s1 = atoi(s.substr(0,2).c_str());
    int s2 = atoi(s.substr(2,2).c_str());
    string ans = "";

    if ((s1 >= 1 && s1 <= 12) && (s2 >= 1 && s2 <= 12)) {
        ans = "AMBIGUOUS";
    } else if (s2 >= 1 && s2 <= 12) {
        ans = "YYMM";
    } else if (s1 >= 1 && s1 <= 12) {
        ans = "MMYY";
    } else {
        ans = "NA";
    }
    cout << ans << endl;

}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >>s;
    string result = "Yes";
    
    if (s[a] == '-') {
        s.replace(a, 1, "1");
        for (char buf : s) {
            unsigned char ss = static_cast<unsigned char>(buf);
            if (!(isdigit(ss))) {
                result = "No";
                break;
            }
        }
    } else {
        result = "No";
    }
    
    cout << result << endl;
}

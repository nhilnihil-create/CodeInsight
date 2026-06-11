#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    bool ok = s[a] == '-';
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i != a) {
            ok &= '0' <= s[i] && '9' >= s[i];
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
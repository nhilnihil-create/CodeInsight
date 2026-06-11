#include <cctype>
#include <iostream>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << s.substr(0, k - 1) << (char)tolower(s[k - 1]) << s.substr(k);
}

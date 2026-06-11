#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    string t = "Festival";
    s.erase(s.end() - t.length(), s.end());
    cout << s << endl;
    return 0;
}

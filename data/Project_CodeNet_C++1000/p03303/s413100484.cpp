#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i * n < s.size(); i++) {
        cout << s[i * n];
    }
    cout << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, k = 0;
    string s;
    cin >> a >> b >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '-') k++;
    if (k == 1 && s[a] == '-') cout << "Yes";
    else cout << "No";
}
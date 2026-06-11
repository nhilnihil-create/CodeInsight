#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        total = s[i] == '+' ? total+1 : total-1;
    }
    cout << total << endl;
    return 0;
}
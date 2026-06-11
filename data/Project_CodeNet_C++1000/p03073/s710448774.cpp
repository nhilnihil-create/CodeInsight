#include <bits/stdc++.h>
using namespace std;


int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && s[i] == '1') count1 += 1;
        if (i % 2 != 0 && s[i] == '0') count1 += 1; 
        if (i % 2 == 0 && s[i] == '0') count2 += 1;
        if (i % 2 != 0 && s[i] == '1') count2 += 1;
    }
    cout << min(count1, count2) << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int counter = 0;
    int ans = 0;
    for (int i=0; i<s.size(); i++) {
        switch(s[i]) {
            case 'A':
            case 'T':
            case 'G':
            case 'C':
                counter++;
                break;
            default:
                ans = max(ans, counter);
                counter = 0;
                break;
        }
    }
    cout << max(ans, counter) << endl;
}
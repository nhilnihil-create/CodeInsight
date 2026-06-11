#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    for (int i = 1; i < n; i++) {
        if (s[i-1][s[i-1].size()-1] != s[i][0]) {
            cout << "No" << endl;
            return 0;
        }
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                cout << "No" << endl;
                return 0;
            }
        } 
    }

    cout << "Yes" << endl;
}
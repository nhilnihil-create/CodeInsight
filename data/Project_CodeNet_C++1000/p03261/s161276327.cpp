#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    for(int i=0; i<n; i++) {
        if(i >= 1 && s[i][0] != s[i-1][s[i-1].size()-1]) {
            cout << "No" <<  endl;
            return 0;
        }
        if(count(s.begin(), s.end(), s[i]) >= 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}

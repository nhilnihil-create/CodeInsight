#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    
    if (s[0] == '0' || s[n-2] == '0' || s[n-1] == '1') {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < n/2; i++) {
        if (s[i] != s[n-2-i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    int cnt = 1;
    cout << "1 2" << endl;
    for (int i = 3; i <= n; i++) {
        cout << cnt << " " << i << endl;
        if (i < n && s[i-2] == '1') cnt = i;
    }
    return 0;
}
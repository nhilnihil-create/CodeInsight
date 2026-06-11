#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if(s[0] == '0' || s[n - 1] == '1'){
        cout << -1;
        // cout << "666";
        return 0;
    }

    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '1' && s[n - 1 - i - 1] == '0') {
            cout << -1;
            // cout << 777;
            return 0;
        }
    }

    int now = 0;
    for(int i = 1; i < n; i++) {
        printf("%d %d\n", now + 1, i + 1);
        if(s[i - 1] == '1') now = i;
    }
}
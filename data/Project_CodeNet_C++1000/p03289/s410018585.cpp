#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    bool one = false, two = false, three = true;
    int n = s.size(), cnt = 0;
    if(s[0] == 'A') {
        one = true;
    }
    for(int i = 1; i < n; i++) {
        if(i>=2 && i < n-1 && s[i] == 'C') {
            cnt++;
        }
        if(s[i] != 'C' && (s[i] < 'a' || s[i] > 'z')) {
            three = false;
        }
    }
    if(cnt == 1) {
        two = true;
    }
    if(one && two && three) {
        cout << "AC\n";
    } else {
        cout << "WA\n";
    }
    return 0; 
}
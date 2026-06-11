#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, ans = "AC";
    cin >> s;
    
    int count = 0;
    
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    
    if (!(islower(s[1]))) {
        cout << "WA" << endl;
        return 0;
    }
    
    if (!(islower(s[s.size() - 1]))) {
        cout << "WA" << endl;
        return 0;
    }
    
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'C') {
            count++;
        } else if (!(islower(s[i]))) {
            ans = "WA";
            break;
        }
    }
    
    if (count != 1) {
        ans = "WA";
    }
    
    cout << ans << endl;
    
    return 0;
}

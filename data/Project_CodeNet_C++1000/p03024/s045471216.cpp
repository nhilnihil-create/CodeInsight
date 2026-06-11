#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,ans = "NO";
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o') {
            count++;
        }
    }
    
    if(count + (15 - s.size()) >= 8) {
        ans = "YES";
    }
    
    cout << ans << endl;
    return 0;
}

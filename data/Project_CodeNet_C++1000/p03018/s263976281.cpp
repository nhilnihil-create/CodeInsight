#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    s += '0';
    long long int a = 0, ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'A') {
            a++;
        } else if(s[i] == 'B' && s[i+1] == 'C') {
            ans += a;
            ++i;
        } else {
            a = 0;
        }
    }
    cout << ans << '\n';
    
    return 0;
}

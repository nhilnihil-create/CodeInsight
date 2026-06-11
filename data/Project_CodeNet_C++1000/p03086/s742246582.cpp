#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    
}
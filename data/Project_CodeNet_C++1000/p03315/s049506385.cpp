#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    int ans = 0;
    for (int i=0; i<4; i++) {
        if (str[i] == '+') ans++;
        else ans--;
    }
    
    cout << ans << endl;
    
    return 0;
}
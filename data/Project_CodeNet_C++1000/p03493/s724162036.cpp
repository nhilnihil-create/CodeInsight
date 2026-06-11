#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[3];
    int ans = 0;
    cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < 3; i++) if(s[i]-'0') ans++;
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '+'){ans += 1;}
        else{ans -= 1;}
    }
    cout << ans << endl;
    return 0;
}
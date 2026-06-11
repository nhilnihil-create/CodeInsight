#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string t = "2019/04/30";
    string ans = "_";
    rep(i,n){
        if(s[i] == t[i]) continue;
        else if(s[i] > t[i]){
            ans = "TBD";
            break;
        }
        else{
            ans = "Heisei";
            break;
        }
    }
    if(ans == "_") ans = "Heisei";

    cout << ans << endl;
}

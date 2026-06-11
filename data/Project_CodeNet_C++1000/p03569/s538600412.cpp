#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int l = 0, r = s.size() - 1, ans = 0;
    while(r - l > 0) {
        if(s[l] == s[r]) l++, r--;
        else {
            if(s[l] == 'x') l++;
            else if(s[r] == 'x') r--;
            else {
                cout << -1 << endl; return 0;
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
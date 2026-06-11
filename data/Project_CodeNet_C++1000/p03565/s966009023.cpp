#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    string ans,b;
    for(int i = 0; i < 50; ++i) ans += 'z';
    b = ans;
    for(int i = 0; i < s.size(); ++i){
        bool flag = true;
        for(int j = 0; j < t.size(); j++){
            if(i+j > s.size() -1) {
                flag = false;
                break;
            }
            if(s[i+j] == '?') continue;
            if(s[i+j] != t[j]) flag = false;
        }
        if(flag){
            string tmp = s;
            for(int k = 0; k < s.size(); ++k){
                if(i <= k && k < i+t.size()) tmp[k] = t[k-i];
                else if(tmp[k] == '?') tmp[k] = 'a';
            }
            ans = min(ans, tmp);
        }
    }
    if(ans == b) cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    if(s.size() < 26){
        vector<bool> vis(26, false);
        rep(i, s.size())vis[s[i]-'a'] = true;
        char c;
        rep(i, 26)if(!vis[i]){
            c = 'a' + i;
            break;
        }
        cout << s + c << endl;
    }else{
        int idx = 0;
        rep(i, s.size()-1)if(s[i] < s[i+1])idx = i;
        vector<bool> vis(26, false);
        rep(i, idx+1)vis[s[i]-'a'] = true;
        for(char c = s[idx] + 1; c <= 'z'; c++){
            if(!vis[c-'a']){
                string ans = s.substr(0, idx);
                cout << ans + c << endl;
                return 0;
            }
        }
    }
}
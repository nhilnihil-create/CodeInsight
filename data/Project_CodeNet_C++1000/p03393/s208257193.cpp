#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.length();
    vector<bool> data(26,false);
    rep(i,n) data[s[i]-'a'] = true;
    
    bool count = true;
    rep(i,26){
        if(data[i] == false){
            string ans = s + (char)('a' + i);
            cout << ans << endl;
            return 0;
        }
    }
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    else{
        string save = s;
        next_permutation(s.begin(),s.end());
        string ans = " ";
        rep(i,26){
            if(save[i]==s[i]) ans += s[i];
            else { ans += s[i]; break; }
        }
        cout << ans << endl;
        return 0;
    }
}
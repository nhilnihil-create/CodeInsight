#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    string s; cin >> s;

    map<char, int> mp;
    for(int i = 0; i < (int)s.size(); i++){
        mp[s[i]]++;
    }

    for(char c = 'a'; c <= 'z'; c++){
        if(0 < mp[c]) continue;
        cout << s + c << endl;
        return 0;
    }

    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    string t = s;
    next_permutation(ALL(s));
    string ans = "";
    for(int i = 0; i < (int)s.size(); i++){
        ans += s[i];
        if(s[i] > t[i]){
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    string s,t;
    cin >> s >> t;
    unordered_map<char,int> mp[2];
    bool ans = true;
    for(int i = 0; i < s.size(); i++){
        mp[0][s[i]] = mp[0][s[i]]*10+i;
        mp[1][t[i]] = mp[1][t[i]]*10+i;
    }    
    for(int i = 0; i < s.size(); i++){
        if(mp[0][s[i]] != mp[1][t[i]]) ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
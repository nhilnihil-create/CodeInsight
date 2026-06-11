#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) mp[s[i]]++;
    if(abs(mp['a'] - mp['b']) > 1){
        cout << "NO" << endl;
    }else if(abs(mp['a'] - mp['c']) > 1){
        cout << "NO" << endl;
    }else if(abs(mp['c'] - mp['b']) > 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
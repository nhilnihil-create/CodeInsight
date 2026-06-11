#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string make_ans(string s, string t, int cur){
    string ans = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == '?') ans += 'a';
        else ans += s[i];
    }
    for(int i=0; i<t.size(); i++){
        ans[cur + i] = t[i];
    }
    return ans;
}

int main() {
    string s,t; cin >> s >> t;
    int cur = -1;
    for(int i=0; i<s.size()-t.size()+1; i++){
        string sub = s.substr(i,t.size());
        //cout << sub << endl;
        for(int j=0; j<t.size(); j++){
            if(sub[j] != t[j] && sub[j] != '?') break;
            if(j == t.size() -1) cur = i;
        }
    }
    if(cur < 0) cout << "UNRESTORABLE" << endl;
    else cout << make_ans(s,t,cur) << endl;
}
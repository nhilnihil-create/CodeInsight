#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s, t;
    cin >> s >> t;
    vector<int> ns(26), nt(26);
    for(int i=0; i<s.size(); i++){
        ns[s[i] - 'a']++;
        nt[t[i] - 'a']++;
        // cout << "a" << s[i] - 'a' << endl;
    }
    
    bool ans = true;
    sort(ns.begin(), ns.end());
    sort(nt.begin(), nt.end());
    
    for(int i=0; i<26; i++){
        if(ns[i] != nt[i]) ans = false;
    }
    
    printf("%s\n", (ans) ? "Yes": "No");
}

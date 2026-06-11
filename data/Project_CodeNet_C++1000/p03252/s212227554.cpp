#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int a[26], b[26];
    for(int i=0; i<26; i++){
        a[i] = 0;
        b[i] = 0;
    }
    for(int i=0; i<s.size(); i++){
        a[s[i] - 'a']++;
        b[t[i] - 'a']++;
    }
    sort(a, a+26);
    sort(b, b+26);
    bool isok = true;
    for(int i=0; i<26; i++){
        if(a[i] != b[i]) isok = false;
    }
    if(isok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
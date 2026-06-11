#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string t;
    cin >> s >> t;
    int n,m;
    n = s.length();
    m = t.length();
    string ans = "UNRESTORABLE";
    bool chk = false;
    for(int i=n-1;i>=m-1;i--){
        if(s[i] == t[m-1] || s[i] == '?'){
            chk = true;
            for(int j=0;j<m;j++){
                if(s[i-j] != t[m-1-j] && s[i-j] != '?'){
                    chk=false;
                    break;
                }
            }
            if(chk){
                for(int j=0;j<m;j++){
                    s[i-j] = t[m-1-j];
                }
                break;
            }
        }
    }
    if(chk){
        for(int i=0;i<n;i++){
            if(s[i]=='?')s[i] = 'a';
        }
        ans = s;
    }
    cout << ans << endl;
}
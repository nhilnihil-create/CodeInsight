#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    vector<int> alp(26, 0);
    int cnt = 0;
    string ans = "";

    for(int i=0; i<s.length(); i++){
        alp[s[i]-'a']++;
        if(alp[s[i]-'a']==1) cnt++;
    }

    if(cnt < 26){
        char tmp;
        for(int i=0; i<26; i++){
            if(alp[i]==0){
                tmp = 'a' + i;
                break;
            }
        }
        ans = s + tmp;
    }else{
        bool flg = false;
        int ids = 0;
        for(int i=1; i<s.length(); i++){
            if(s[i] > s[i-1]){
                flg = true;
                ids = i;
            }
        }
        if(!flg){
            ans = "-1";
        }else{
            string t = s;
            next_permutation(s.begin(), s.end());
            for(int i=0; i<t.size(); i++){
                cout << s[i];
                if(s[i] != t[i]){
                    break;
                }
            }
            cout << "\n" << endl;
            return 0;
        }
        
    }

    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    if(s.length() < 26){
        for(int i=0; i<26; i++){
            char c = 'a' + i;
            if(s.find(c) == s.npos){
                s += c;
                cout << s << endl;
                return 0;
            }
        }
    }

    int x = 25;
    set<char> letter = {s[x]};

    while(x > 0 && s[x-1] > s[x]){
        letter.insert(s[x-1]);
        x -= 1;
    }
    x -= 1;
    if(x == -1){
        cout << -1 << endl;
        return 0;
    }

    string ans = s.substr(0,x);
    ans += *letter.lower_bound(s[x]);
    //letter.insert(s[x]);
    //for(char l : letter) ans += l;
    
    cout << ans << endl;
    return 0;
}
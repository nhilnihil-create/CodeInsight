#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool isAllNine(string s){
    rep(i,s.size()){
        if(s[i] != '9'){
            return false;
        }
    }
    return true;
}

int main() { 
    string s;
    cin >> s;
    if(s.size()==1){
        cout << s<<endl;
        return 0;
    }

    if(isAllNine(s.substr(1,s.size()-1))){
        cout << s[0]-'0' + (s.size()-1)*9 <<endl;
        return 0;
    }

    int ans = s[0]-'1';
    ans += (s.size()-1) * 9;
    cout << ans<<endl;
}
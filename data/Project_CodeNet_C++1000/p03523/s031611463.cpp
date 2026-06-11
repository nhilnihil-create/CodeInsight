#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string s, c;
    cin >> s;
    int n = s.length();
    int j = 0;
    int g = 0;
    int d = 0;
    rep(i,n){
        if(s[i] != 'A'){
            c += s[i];
        }
    }

    rep(i,n){
        if(s[i] == s[i+1]){
            j = 1;
        }
        if(s[i] == 'K' && s[i+1] != 'I'){
            g = 1;
        }
        if(s[i] == 'I' && s[i+1] != 'H'){
            d = 1;
        }
    }

    if(c == "KIHBR" && j < 5 && j == 0 && g == 0 && d == 0){
        cout << "YES";
        }else{
            cout << "NO";
        }
}
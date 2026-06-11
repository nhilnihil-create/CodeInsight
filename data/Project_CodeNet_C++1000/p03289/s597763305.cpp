#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    bool flag = false;
    if (isupper(s[1]) || isupper(s[s.size()-1])){cout << "WA" << endl; return 0;}
    for (int i = 0; i < s.size(); i++){
        if (i == 0 && s[i] != 'A'){cout << "WA" << endl; return 0;}
        if (s[i] == 'C'){
            if (flag){cout << "WA" << endl; return 0;}
            else{flag = true;}
        }
    }
    if (flag){cout << "AC" << endl;}
    else{cout << "WA" << endl;}
    return 0;
}
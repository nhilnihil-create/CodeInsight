#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (int i=0; i<s.size(); i++){
        if ((i==a && s[i]!='-') || (i!=a && !(0<=s[i]-'0' && s[i]-'0'<=9))){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
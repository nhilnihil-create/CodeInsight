#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s.at(i) == '1') s.at(i) = '9';
        else s.at(i) = '1';
    }

    cout << s << endl;
}
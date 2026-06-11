#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t; cin >> s >> t;
    for(int i = 0; i < s.size(); i++) {
        if(s==t) {
            cout << "Yes" << endl;
            return 0;
        } else {
            s = s.back() + s.substr(0, s.size()-1);
        }
    }
    cout << "No" << endl;
    return 0;
}
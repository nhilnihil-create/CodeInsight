#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s,t;
    cin >> s >> t;
    string tmp = s;
    for(int i=0;i<s.size();i++) {
        tmp = tmp[s.size()-1] + tmp.substr(0,s.size()-1);
        if(tmp == t) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    
    return 0;
}

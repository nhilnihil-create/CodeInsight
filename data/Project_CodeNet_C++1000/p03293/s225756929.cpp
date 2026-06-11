#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s, t;
    cin >> s >> t;
    for (int i=0; i<s.size(); i++){
        s = s[s.size()-1] + s;
        s.pop_back();
        if (s == t){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
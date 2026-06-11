#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<char> s(3);
    string abc= "abc";
    for (int i=0; i<3; i++) cin >> s[i];
    sort(s.begin(), s.end());
    for (int i=0; i<3; i++){
        if (abc[i] != s[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();

    for(int i = 0; i < len - 8; i++){
        cout << s[i];
    }
    cout << endl;
}
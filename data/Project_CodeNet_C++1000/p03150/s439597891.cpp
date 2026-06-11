#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    for(int i=0; i<=7; i++){
        string test = s.substr(0,i) + s.substr(n-7+i,7-i);
        if(test == "keyence"){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
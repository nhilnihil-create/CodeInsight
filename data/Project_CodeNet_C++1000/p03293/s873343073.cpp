#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    
    s += s;
    if (s.find(t) == string::npos){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string k="keyence";
    bool tf=false;
    for (int i = 0; i < 7; i++){
      if(s.substr(0,i)==k.substr(0,i) && s.substr(s.length()-7+i,7-i)==k.substr(i,7-i)){
          tf=true;
      }
    }
    if(tf){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}
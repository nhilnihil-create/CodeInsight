#include <bits/stdc++.h>
using namespace std;

int main() {
 string s;
 cin >> s;
 int count = 0;
 for(char i:s){
    if (i == 'o') count += 1;
 }
 if ((15-s.size())+count >= 8) cout << "YES"<< endl;
 else cout << "NO" << endl;
}
  
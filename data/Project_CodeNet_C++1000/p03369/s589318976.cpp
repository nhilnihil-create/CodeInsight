#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  int counter=0;
  cin >> s;
  if(s[0]=='o') ++counter;
  if(s[1]=='o') ++counter;
  if(s[2]=='o') ++counter;
  
    cout << 700+100*counter << endl;
}
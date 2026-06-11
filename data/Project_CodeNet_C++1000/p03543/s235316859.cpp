#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  string a,b,c,d;
  a=s[0]; b=s[1]; c=s[2]; d=s[3];
  if((a==b && a==c) || (b==c && b==d)){
    cout << "Yes" << endl;
  }else{
      cout << "No" << endl;
  }
}
  
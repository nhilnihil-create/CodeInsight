#include <bits/stdc++.h>
using namespace std;

int main(){
  char a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a==b&&a==c) cout << "Yes" << endl;
  else if(b==c&&b==d) cout << "Yes" << endl;
  else cout << "No" << endl;
}
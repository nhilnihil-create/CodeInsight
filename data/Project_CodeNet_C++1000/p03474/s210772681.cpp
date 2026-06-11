#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b; string s; cin >> a >> b >> s;
  for(int i=0; i<a; i++) {
    if(isdigit(s[i])) continue;
    else {
      cout << "No" << endl;
      return 0;
    }
  }
  if(s[a]!='-') {
    cout << "No" << endl; return 0;
  } else {
    for(int i=a+1; i<a+b+1; i++) {
      if(isdigit(s[i])) continue;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
	return 0;
  }
}

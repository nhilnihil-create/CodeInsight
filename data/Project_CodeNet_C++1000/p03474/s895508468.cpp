#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  
  string t="No";
  
  int c=0;
  
  for(int i=0; i<a; i++){
    if(s[i] != '-'){
      c++;
    }
  }
  if(s[a] == '-'){
    c++;
  }
  for(int i=a+1; i<a+b+1; i++){
    if(s[i] != '-'){
        c++;
    }
  }
  
  if(c == a+b+1){
    t="Yes";
  }

  cout << t << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s="ABC";
  int n;
  cin >> n;
  
  if(n >= 1000){
    s = "ABD";
  }
  
  cout << s << endl;
	return 0;
}

#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if(a <= c && c <= a + b){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl; 
  }
	return 0;
}

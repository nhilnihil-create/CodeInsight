#include <bits/stdc++.h>
using namespace std;

int main() {
  
	string s;
  	cin >> s;
  	int x = 0;
  
  	for (int i = 0; i < 3; i++){
      
      if (s.at(i) == '1'){
        x = x + 1;
      }
      
    }
  
  cout << x << endl;

 }
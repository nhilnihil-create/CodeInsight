#include <bits/stdc++.h>
using namespace std;

int main() {
  	string s;
  	int p = 700;
  	for(int i = 0; i < 3; i++){
    	cin >> s;
    }
  	for(int i = 0; i < 3; i++){
    	if(s.at(i) == 'o') {
          p += 100;
        }
    }
  	cout << p << endl;
  	return 0;
}

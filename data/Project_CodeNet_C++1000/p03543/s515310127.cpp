#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string n;
  //int i = 0;
  cin >> n;
  
  	if ((n[0] == n[1] && n[1] == n[2])
        || (n[1] == n[2] && n[2] == n[3])) {
  		cout << "Yes" << endl;
  	} else {
  		cout << "No" << endl;
  	}
}
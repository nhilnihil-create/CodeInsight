#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; //ひなあられ数
	int y = 0;
  	int i;
	cin >> N;
  
	for (i = 0; i < N; i++) {
      string c;
      cin >> c;
      
	 if (c == "Y") {
       y += 1;
       break;
      }
    }
  
  	if (y > 0) {
        cout << "Four" << endl;
    } else {
		cout << "Three" << endl;
    }
}

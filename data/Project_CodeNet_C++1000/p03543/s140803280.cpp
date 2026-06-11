#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N, x, y ;
  	cin >> N ;
  	x = N - N % 10 ;
  	y = N - N / 1000 * 1000 ;
  
  	if (x % 111 == 0 || y % 111 == 0) {
      cout << "Yes" ;
    }
  else {
    cout << "No" ;
  }
  
}

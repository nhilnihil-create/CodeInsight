#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N, A, B, x ;
  	cin >> N >> A >> B ;
  	x = N * A ;
  
  if (x == B) {
    cout << x ;
  }
  else if (x <= B) {
    cout << x ;
  }
  else {
    cout << B ;
  }
}
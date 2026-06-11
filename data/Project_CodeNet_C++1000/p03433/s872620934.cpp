#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
  	cin >> N;
  
  	int A;
  	cin >> A;
  
  	if ( (N % 500) <= A) {
      	cout << "Yes" << endl;
    }
  	else {
      	cout << "No" << endl;
    }
}
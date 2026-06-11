#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
  	
  	int total = 0;
    if(C > A+B+1) total += A+B+1;
  	else total += C;
	
  	cout << B + total << endl;
}
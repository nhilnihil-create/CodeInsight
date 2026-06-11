#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,A,X,Y;
	cin >> N >> A;
	//Xは商、Yは余り
	X = N/500;
	Y = N-500*X;
	
	if ((A > Y)||(A == Y)){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
  
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	int A, B, C;
	cin >> A >> B >> C;

	if(A==B){
		cout << C <<endl;
	}

	if(B==C){
		cout << A <<endl;
	}

	if(A==C){
		cout << B <<endl;
	}
}
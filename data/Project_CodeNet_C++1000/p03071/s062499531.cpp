#include <bits/stdc++.h>

using namespace std;

int main(){
	int A, B, suma = 0;
	cin >> A >> B;
	suma = max(A,B);
	if(A >= B) {
		A--;
	}
	else {
		B--;
	}
	suma += max(A,B);
	cout << suma;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){

	int N, X;

	cin >> N;

	X = N/100000000 + N/10000000%10 + N/1000000%10 + N/100000%10 + N/10000%10 + N/1000%10 + N/100%10 + N/10%10 + N%10;

	if ( N % X == 0 ){
		cout << "Yes" << endl;
	}

	else
		cout << "No" << endl;
}
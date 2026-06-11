#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N, A;

	cin >> N >> A;

	while( N >= 500){
		N = N - 500;
	}
	if( N <= A ){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,P,x = 0;
	cin >> N;
	P = N;
	
	while (N > 0){
		x = x + (N % 10);
		N = N / 10;
	}
	
	if ((P % x) == 0){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}

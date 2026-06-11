#include <bits/stdc++.h>
using namespace std;
int main (){
	
	int A[5], k;
	for(int i=0; i<5; i++){
		cin >> A[i];
	}
	cin >> k;
	
	if (A[4] - A[0] > k){
		cout << ":(";
	}else{
		cout << "Yay!";
	}
	
	return 0;
}
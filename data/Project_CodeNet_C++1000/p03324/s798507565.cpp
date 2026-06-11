#include <bits/stdc++.h>
using namespace std;

int main(){
	int D, N;
	cin >> D >> N;

	if(D==0){
		if(N==100){
			cout << "101" << endl;
		}
		else{
			cout << N << endl;
		}
	}
	else if (D==1) {
		if(N==100){
			cout << "10100" << endl;
		}
		else{
			cout << 100*N << endl;
		}
	}
	else if (D==2) {
		if(N==100){
			cout << "1010000" << endl;
		}
		else{
			cout << 10000*N << endl;
		}
	}
}

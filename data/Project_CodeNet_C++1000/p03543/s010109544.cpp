#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int N, num, n1, n2, count=0;

	cin >> N;
	
	n1 = N%10;
	num = N/10;

	for(int i=1;i<4;i++){
		n2 = num%10;
		num = num/10;

		if(n1 == n2){
			count++;
			if(count >=2 ){
				cout << "Yes" << endl;
				return 0;
			}
		}
		else{
			n1 = n2;
			count = 0;
		}

	}

	if(count >=2 ){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
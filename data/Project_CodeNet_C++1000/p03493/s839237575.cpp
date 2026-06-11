#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int s;
	int count=0;
	int num;

	cin >> s;

	num = s;

	for(int i=0;i<3;i++){
		if(num%10==1){
			count++;
		}
		num = num/10;
	}

	cout << count << endl;

}
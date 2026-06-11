#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int N, A;//Nは合計金額、Aは1円の枚数
	int rest;

	cin >> N >> A;

	rest = N % 500;

	if((rest==0)||(rest<=A)){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
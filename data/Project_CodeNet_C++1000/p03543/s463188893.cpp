#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	if(N/1000 == N/100%10 && N/1000 == N/10%100%10){
	cout << "Yes" << endl; //1000の位と100の位が一致、かつ1000の位と10の位が一致
	}

	else if(N/100%10 == N%1000%100%10 && N/100%10 == N/10%100%10){
	cout << "Yes" << endl; //100の位と1の位が一致、かつ100の位と10の位が一致
	}

	else{
	cout << "No" << endl;
	}
}

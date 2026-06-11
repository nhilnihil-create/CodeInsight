#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, vec[210];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> vec[i];
	}
	int num=0;
	while(true){
		bool exist_odd=false;
	for (int i=0; i<n; i++){
		if (vec[i] % 2!=0) exist_odd=true;
	}
		if (exist_odd) break;
		for(int i=0; i<n; i++){
			vec[i] /= 2;
	}
	num ++;
	}
	cout << num << endl;
}


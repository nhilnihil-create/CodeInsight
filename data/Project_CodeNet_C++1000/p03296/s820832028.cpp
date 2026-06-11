#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,c=0;
	cin >> n;
	int ar[n];
	for(int i=0; i<n; i++){
		cin >> ar[i];
	}
	for(int i=1; i<n;){
		if(ar[i]==ar[i-1])c++,i+=2;
		else i++;

	}
	cout << c <<endl;
	return 0;
}
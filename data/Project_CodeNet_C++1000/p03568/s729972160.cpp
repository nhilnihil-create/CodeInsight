#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,even=0;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		if(temp%2==0) even++;
	}
	cout << pow(3,n)-pow(2,even);
	
}

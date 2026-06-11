#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int temp, sum = 0;
	for(int i = 0;i<n;i++){
		cin >> temp;
		sum+=temp;
		
	}
	cout << sum-n;
 }

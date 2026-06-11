#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b){
	return a - b + 1;
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
	
	
	return 0;
}
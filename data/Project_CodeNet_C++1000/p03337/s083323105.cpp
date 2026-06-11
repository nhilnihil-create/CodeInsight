#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	
	int a,b, sum, min, mult;
	cin >> a >> b;
	
	sum = a + b;
	min = a - b;
	mult = a * b;

	cout << max( {sum, min, mult} ) << endl;

	return 0;
}
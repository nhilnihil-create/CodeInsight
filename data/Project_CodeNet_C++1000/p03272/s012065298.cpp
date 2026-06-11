#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, i; 
	cin >> n >> i;
	if(n - i == 0)
		cout << 1 << endl;
	else
		cout << (n - i) + 1 << endl;

	return 0;
}
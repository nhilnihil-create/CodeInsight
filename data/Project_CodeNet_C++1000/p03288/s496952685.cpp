#include <bits/stdc++.h>
using namespace std;

int main(){
	int r; 
	cin >> r;
	if(r < 1200)
		cout << "ABC";
	if(r >= 1200 && r < 2800)
		cout << "ARC";
	if(r >= 2800)
		cout << "AGC";

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int Max(int c1, int c2, int c3){
	int h = max(c1, c2);
	return max(h, c3);
}

int main(){
	int a, b, c=0;
	cin >> a >> b;
	int c1 = 2*a-1, c2 = 2*b-1, c3 = a+b;
	cout << Max(c1, c2, c3);
	return 0;	
}
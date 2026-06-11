#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a, b, c, sum = 0;
	cin >> a >> b >> c;
	if (b == c){
		sum = b + c;
	}
	if (b < c){
		sum = b + b + 1;
		c -= (b + 1);
		if(a){
			sum += min(a,c);
		}
	}
	else {
		sum = a + c;
	}
	cout << sum;
}


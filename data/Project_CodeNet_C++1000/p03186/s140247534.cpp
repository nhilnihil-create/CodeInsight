#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, c; cin >> a >> b >> c;
	
	long long t = 0;
	
	if(b == c){
		t = b + c;
	}
	else if(b < c){
		t = b + b + 1;
		c -= (b + 1);
		if(a){
			t += min(a, c);	
		}
	}
	else {
		t = b + c;
	}
	
	cout << t;
	return 0;
}

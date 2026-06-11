#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin >> x;
	set<int> s;
	for(int i = 2; i< 33; i++){
		for(int j=2; j<11; j++){
			int result = pow(i,j);
			if (result <= 1000) s.insert(result);
			else break;
		}
	}
	s.insert(1);
	for(int i = x; i>=1; i--){
		if (s.count(i)) {cout << i; return 0;}
	}
	
 }

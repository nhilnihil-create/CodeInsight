// B - Exponential
#include <bits/stdc++.h>
using namespace std;

int main(){
	int x; cin>>x;
	int ans = 1;
	for(int i=2; i*i<=x; ++i){ // [2, sqrt(x)]
		int a = i;
		while(a < x){
			a *= i;
			if(a <= x) ans = max(ans, a);
		}
	}
	cout<< ans <<endl;
}

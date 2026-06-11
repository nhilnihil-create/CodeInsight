#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N;
	long long mn = 1e9 + 7; 
	long long sum = 0; 
	for(int i = 0; i < N; i++){
		long long a, b; 
		cin >> a >> b; 
		sum += a; 
		if(a > b) mn = min(mn, b); 
	}
	if(mn == 1e9 + 7){
		cout << 0 << endl; return 0; 
	}
	cout << sum - mn << endl; 
}
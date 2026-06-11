#include <iostream>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n;
	cin >> n;
	int p[n];
	int max_value = 0;
	int sum = 0;
	
	rep(i,n) {
		cin >> p[i];
		max_value = max_value > p[i] ? max_value:p[i];
		sum += p[i];
	}
	
	sum -= max_value/2;
	
	cout << sum << endl;
	return 0;
}
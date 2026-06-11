#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	
	int Q;
	cin >> Q;
	
	for(int i = 0; i < Q; i++){
		
		long long int A, B;
		cin >> A >> B;
		if(A > B){
			swap(A, B);
		}
		if(B - A == 0 || B - A == 1){
			cout << (A - 1) * 2 << endl;
			continue;
		}
		long long int qq = sqrt(A * B);
		if(qq * qq == A * B){
			qq--;
		}
		long long int ans = qq * 2 - 1;
		if(qq * (qq + 1) >= A * B){
			ans--;
		}
		cout << ans << endl;
	}
	
	return 0;
}

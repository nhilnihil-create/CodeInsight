#include <iostream>
#include <numeric>
using namespace std;
int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		long long A, B, C, D;
		cin >> A >> B >> C >> D;
		if (A > C){
			A = (A - C - 1) % B + C + 1;
		}
		if (A < B){
			cout << "No" << endl;
		} else if (B > D){
			cout << "No" << endl;
		} else if (B < C){
			cout << "Yes" << endl;
		} else if (B - C <= gcd(B, D)){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
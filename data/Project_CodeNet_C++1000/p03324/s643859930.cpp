#include <iostream>
using namespace std;

int main() {
	int D, N;
	long long A=1;
	cin >> D >> N;
	for (int i=0; i<D; i++){
	    A*=100;
	}
	if (N<=99) cout << A*N << endl;
	else cout << A*101 << endl;
}

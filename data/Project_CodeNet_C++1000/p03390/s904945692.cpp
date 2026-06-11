#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
	int Q;
	cin >> Q;
	while (Q --){
		long long a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		if (a + 1 >= b)
			cout << 2 * a - 2 << endl;
		else{
			long long c = sqrt(a * b + 0.5);
			while (c * c >= a * b)
				-- c;
			if (c * (c + 1) >= a * b)
				cout << 2 * c - 2 << endl;
			else
				cout << 2 * c - 1 << endl;
		}
	}
}
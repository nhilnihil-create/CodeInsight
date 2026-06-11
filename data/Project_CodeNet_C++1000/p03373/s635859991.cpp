#include <iostream>
using namespace std;
int main(){
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int total=0;
	if (X < Y) {
		if (2 * C <= A + B)
			total += 2 * X * C;
		else total += (A + B) * X;
		
		if (2 * C <= B)
			total += 2 * (Y - X) * C;
		else total += (Y - X) * B;
	}
	else {
		if (2 * C <= A + B)
			total += 2 * Y * C;
		else total += (A + B) * Y;

		if (2 * C <= A)
			total += 2 * (X - Y) * C;
		else total += (X - Y) * A;
	}
	cout << total;
}
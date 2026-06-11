#include <iostream>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int R = N * A;
	if (R <= B) {
		cout << R;
	}
	else
	{
		cout << B;
	}
}
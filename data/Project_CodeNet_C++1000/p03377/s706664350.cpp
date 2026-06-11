#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int A, B, X;

	cin >> A >> B >> X;

	

	if (A > X || X > A + B){
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}

	return 0;

}

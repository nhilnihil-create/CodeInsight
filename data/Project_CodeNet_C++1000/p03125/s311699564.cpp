#include <iostream>
using namespace std;

int main(void)
{
	int A, B; cin >> A >> B;
	
	if (B%A != 0)cout << B - A << endl;
	else cout << A + B << endl;


	return 0;
}
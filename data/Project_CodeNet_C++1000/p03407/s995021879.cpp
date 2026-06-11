#include <iostream>
using namespace std;
int main() 
{
	int A, B, C;
	cin >> A >> B >> C;
	if (C <= A + B) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}
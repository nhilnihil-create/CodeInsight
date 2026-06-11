#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	char A;
	char B;

	cin >> A >> B;

	if (A > B) {
		cout << ">";
	} else if (A < B){
		cout << "<";
	} else {
		cout << "=";
    }

	return 0;
}

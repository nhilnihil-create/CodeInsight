#include <iostream>
 
using namespace std;
 
int main()
{
	int A, B;
	cin >> A >> B;
    if (A > 8 || B > 8) {
    	cout << ":(\n";
    }
    else {
    	cout << "Yay!\n";
    }
}
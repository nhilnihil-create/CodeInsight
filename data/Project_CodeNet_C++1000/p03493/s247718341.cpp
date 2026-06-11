
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << (n / 100) + (n % 10) + (n -((n/100)*100+(n%10)))/10 << endl;

}


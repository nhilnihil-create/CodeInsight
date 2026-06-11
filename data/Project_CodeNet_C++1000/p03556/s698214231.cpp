#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i = static_cast<int>(sqrt(n));
	cout << i*i << endl;
	return 0;
}

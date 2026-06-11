#include <iostream>
using namespace std;


int main()
{
    int a, b;
    cin >> a >> b ;

	if((a&1) == 0 || (b&1) == 0 )
	{
		cout <<"Even";
	}
	else
	{
		cout << "Odd";
	}

	return 0;
}
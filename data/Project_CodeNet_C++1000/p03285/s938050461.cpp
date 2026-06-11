#include <iostream>
using namespace std;
string check(int a)
{
	int arr[] = {1,2,3,5,6,9,10,13,17};
	for(int i = 0; i < sizeof arr/sizeof arr[0]; i++)
		if( a == arr[i] )
			return "No";
	return "Yes";
}
int main()
{
	int a;
	cin >> a;
	cout << check( a % 28 );
}
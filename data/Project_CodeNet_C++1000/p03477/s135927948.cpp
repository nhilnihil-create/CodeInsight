#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int LLI;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if( a + b < c + d )
		cout << "Right";
	else if( a + b == c + d )
		cout << "Balanced";
	else cout << "Left";
}
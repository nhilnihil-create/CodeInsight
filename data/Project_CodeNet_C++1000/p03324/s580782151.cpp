#include <iostream>
using namespace std;
typedef long long int LLI;
LLI pow(int x, int exp)
{
	LLI res = 1;
	for(int i = 0; i < exp; i++)
		res *= x;
	return res;
}
int main()
{
	LLI d, n;
	cin >> d >> n;
  	if( n < 100 )
		cout << pow(100,d)*n;
  	else cout << pow(100,d) * 101;
}
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int LLI;
int solve(int a, int b)
{
	if( (a + b) % 2 == 0)
		return (a+b)/2;
	else
		return (a+b+1)/2;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout  << solve(a,b);
	
}
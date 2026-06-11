#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
	LLI first = 2, second = 1, tmp;
	int n;
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		tmp = second;
		second += first;
		first = tmp;
	}
	cout << second;
}
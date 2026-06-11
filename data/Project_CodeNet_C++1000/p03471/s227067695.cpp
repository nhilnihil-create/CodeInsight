#include <iostream>
using namespace std;
typedef long long int LLI;

void solution(LLI n, LLI y)
{
	int diff = y - n;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n-i; j++)
			if( y - n == 9*i + 4*j )
			{
				cout << i << " " << j << " " << n-i-j;
				return;
			}
	cout << "-1 -1 -1";
}

int main()
{
	LLI n, y;
	cin >> n >> y;
	y /= 1000;
	solution(n,y);
}
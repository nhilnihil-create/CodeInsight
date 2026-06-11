#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;

struct traveling{
	LLI t;
	LLI x;
	LLI y;
};

string solve(LLI & n)
{
	traveling a, b;
	LLI distance, time;
	cin >> a.t >> a.x >> a.y;
	
	if( a.t < a.x + a.y )
		return "No";

	for(int i = 1; i < n; i++)
	{
		cin >> b.t >> b.x >> b.y;
		distance = abs( a.x - b.x ) + abs( a.y - b.y );
		time = b.t - a.t;
		
		if( distance > time )
			return "No";
		else if( ( time - distance ) % 2 == 1 )
			return "No";
		a = b;
	}
	return "Yes";
}

int main()
{
	LLI n;
	cin >> n;
	cout << solve(n);
}
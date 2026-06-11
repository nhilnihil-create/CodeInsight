#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	LLI a, b, k;
	cin >> a >> b >> k;
	if( 2*k > b - a )
		for(int i = a; i <= b; i++)
			cout << i << "\n";
	else{
		for(int i = a; i < a+k; i++)
			cout << i << "\n";
		for(int i = b-k+1; i <= b; i++)
			cout << i << "\n";
	}
}
#include <iostream>
using namespace std;

int main()
{
	int n, a, b;
	cin >>n >>a >>b;

	int dist = b - a;
	if(dist % 2 == 1){
		cout <<"Borys\n";
	}
	else{
		cout <<"Alice\n";
	}
	return 0;
}

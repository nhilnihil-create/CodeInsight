// g++ MoveandWin.cpp -o MoveandWin
#include <iostream>
#include <cmath>
#define endl "\n"

using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,a,b;

	cin>>n;
		
	cin >> a >> b;
	m=abs(a-b);
	if(m&1)
		cout << "Borys"<< endl;
	else
		cout << "Alice"<< endl;

	return 0;
}
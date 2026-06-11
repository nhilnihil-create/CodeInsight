#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int a,b,c;
cin >> a >> b >> c;

if((a*c)<=b)
{
	cout << c << endl;
}
else if((a*c)>b)
{
	cout << b/a << endl;
}

	return 0;
}










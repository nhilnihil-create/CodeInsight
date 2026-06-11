#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int a,b,c,d,e,k;
cin >> a >> b >> c >> d >> e >> k;

if(b-a<=k && c-a<=k && d-a<=k && e-a<=k && c-b<=k && d-b<=k && e-b<=k && d-c<=k && e-c<=k && e-d <=k )
{
	cout << "Yay!" << endl;
}
else
{
	cout << ":(" << endl;
}
	return 0;
}










#include <iostream>
#include <algorithm>
using namespace std;


int main ()
{

 int a,p;
 
 cin >> a >> p;
 
if(a>=13)
{
	cout << p << endl;
}
else if(a>=6 && a<=12)
{
	cout << p/2 << endl ;
}
else
{
	cout << "0" << endl;
}

	return 0;
}










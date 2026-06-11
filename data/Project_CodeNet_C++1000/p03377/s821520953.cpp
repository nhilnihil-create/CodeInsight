#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	if (z < x)
		cout << "NO";
	else if (z>x&&x+y<z)
		cout << "NO";
	else 
		cout << "YES";
}
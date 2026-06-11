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
	int x, y, z, w,a=0;
	cin >> x >> y >> z >> w;
	if (abs(x - z) <= w)
		cout << "Yes";
	else if (abs(z - y) <= w&& abs(x - y) <= w)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
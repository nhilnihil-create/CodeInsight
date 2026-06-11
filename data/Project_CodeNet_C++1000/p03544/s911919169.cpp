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
	long long x = 2, y = 1,z=0,w;
	cin >> w;
	if (w == 1) {
		cout << 1;
	}
	else {
		for (int i = 1; i < w; i++) {



			z = (x + y);

			x = y;
			y = z;
		}
		cout << z;
	}
    return 0;
}
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
	string x;
	cin >> x;
	int y = 0;
	for (int i = 0; i < 3; i++) {
		if (x[i] == 'o')
			y++;
	}
	cout << 700 + 100 * y;
}
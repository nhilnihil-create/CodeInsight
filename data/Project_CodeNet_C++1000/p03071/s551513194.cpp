#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int x,y;
cin >> x >> y;

cout <<  max((max((x+(x-1)),(y+(y-1)))),(x+y))  << endl;

	return 0;
}










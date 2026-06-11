#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <queue> //C++
#include <string> //C++
#include <iostream> //C++
#include <vector> //C++
#include <algorithm> //C++
using namespace std; //C++




int main()
{
	int x, y, i=1;

	cin >> x >> y;
	
	if (x % y == 0) cout << "-1";

	else cout << x;	
}
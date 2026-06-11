#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x = x2 - x1;
	int y = y2 - y1;

	cout << x2 - y << " " << y2 + x << " " << x1 - y << " " << y1 + x << endl;
	return 0;
}
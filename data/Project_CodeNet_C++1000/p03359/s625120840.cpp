#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(ll i=(x);i<(y);i++)
#define disp(a) cout << a << endl;
typedef long long ll;
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a <= b) {
		disp(a);
	}
	else {
		disp(a-1);
	}

}
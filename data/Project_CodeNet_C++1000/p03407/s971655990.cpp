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
	int A, B, C;
	cin >> A >> B >> C;
	if (A + B >= C){
		disp("Yes"); 
	}
	else {
		disp("No");
	}
}
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
	int a, b, c, d;
	vector<int> v;
	cin >> a >> b >> c >> d;
	v.push_back(abs(a-b));
	v.push_back(abs(b-c));
	v.push_back(abs(c-a));

	if (v[2]<=d) {
		disp("Yes");
	}
	else if(v[0]<=d&&v[1]<=d){
		disp("Yes");
	}
	else {
		disp("No");
	}

}
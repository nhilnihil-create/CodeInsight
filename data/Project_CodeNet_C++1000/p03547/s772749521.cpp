#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	char X,Y;
	cin >> X >> Y;
	if((int)X<(int)Y){
		cout << "<" << endl;
	}
	else if((int)X>(int)Y){
		cout << ">" << endl;
	}
	else{
		cout << "=" << endl;
	}

}
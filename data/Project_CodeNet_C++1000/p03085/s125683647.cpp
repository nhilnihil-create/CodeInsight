#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	char c;
	cin >> c;
	if(c == 'A')
		cout << "T";
	else if(c == 'T')
		cout << "A";
	else if(c== 'G')
		cout << "C";
	else
		cout << "G";
	return 0;
}
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
 
int main() {
	int a,b,c,d;
	cin >> a >> b >>c >>d;
	if ((a +b) > (c+d)) cout << "Left" << endl;
	else if ((a+b) == (c+d)) cout << "Balanced" << endl;
	else cout << "Right" << endl;
	return 0;
}

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
	char a,b;
	cin >> a >> b;
	if (a == b) {
		cout << '=' << endl;
	} else if (a < b) cout << '<' << endl;
	else cout << '>' << endl;
	return 0;
}

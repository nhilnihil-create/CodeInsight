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
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	if(b/a >= c)
		cout << c;
	else if(a > b)
		cout << 0;
	else if(b/a < c)
		cout << b/a;
	return 0;
}
#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>

using ll = long long;
using namespace std;
ll M = 1000000000000000;


int main()
{
	string n;
	cin >> n;
	int iti=count(n.begin(), n.end(), '1');
	int zero = count(n.begin(), n.end(), '0');
	int ans = min(iti, zero);
	cout << ans * 2;

}
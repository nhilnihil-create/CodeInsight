#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	string s;
	cin >> s;
	int a, b;
	a = atoi(s.substr(0, 2).c_str());
	b = atoi(s.substr(2, 2).c_str());

	bool x, y;
	x = y = false;
	if (1 <= a && a <= 12) x = true;
	if (1 <= b && b <= 12) y = true;
		
	if (x && y) cout << "AMBIGUOUS" << "\n";
	
	if (x && !y) cout << "MMYY" << "\n";
		
	if (!x && y) cout << "YYMM" << "\n";
			
	if (!x && !y) cout << "NA" << "\n";
	
	



	return 0;
}
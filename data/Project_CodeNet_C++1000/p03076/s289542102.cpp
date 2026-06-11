#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int minAns = 1010101010;
	vector<int> a(5);
	rep(i, 5) cin >> a[i];
	
	do {
		int ans = 0;
		rep(i, 5)
		{
			if (ans % 10 != 0) while (ans % 10 != 0) ans++;
			ans += a[i];
		}
		minAns = min(ans, minAns);
		
	} while (std::next_permutation(a.begin(), a.end()));
	cout << minAns << endl;
	return 0;
}
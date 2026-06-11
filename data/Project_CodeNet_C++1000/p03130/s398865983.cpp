#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>

using namespace std;


int main()
{
	string str,str2[200000],strmemo="";
	long long int n, m, a[20], b[20] = {}, c, d, e, f, now[200][200] = {}, x[200006], y[200006], X = 0, Y = 0;
	const long long int mod = 1000000007;
	
	for (int i = 1; i<= 6; i++) {
		cin >> a[i];
		b[a[i]]++;
	}
	sort(b + 1, b + 5);
	if (b[4] == 3) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	
}

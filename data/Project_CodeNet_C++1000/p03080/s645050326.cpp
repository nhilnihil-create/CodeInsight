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
	long long int n, m, a, b, c, now[200][200] = {},x[200006],y[200006],X=0,Y=0;
	const long long int mod = 1000000007;
	cin >> n >>str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'R') {
			X++;
		}
		else {
			X--;
		}
	}
	if (X > 0) {
		cout << "Yes" << endl;
	}else{

		cout << "No" << endl;
	}
	
}

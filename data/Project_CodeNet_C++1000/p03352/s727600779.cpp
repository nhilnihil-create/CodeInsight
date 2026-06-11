#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;
int main()
{
	int n; cin >> n;
	int mx = 1;
	for (int i = 2; i * i <= n; ++i) {
		int sqr = i;
	//	cout << "i   "<<i << endl;
		while (sqr * i <= n)

		{
			sqr *= i;
		}
		mx = max(sqr, mx);
		//cout << mx << endl;
	}
	cout << mx;
	
}
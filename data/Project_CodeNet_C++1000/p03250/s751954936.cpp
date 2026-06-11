#include <iostream>
#include <string>
#include <iomanip>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main()
{
	int x[3], max = 0;
	rep(i,3){
		cin >> x[i];
		if(x[i] > max) max = x[i];
	}
	cout << x[0]+x[1]+x[2]+9*max;
	return 0;
}
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
	if(max == x[0]) cout << x[0]*10+x[1]+x[2];
	else if(max == x[1]) cout << x[1]*10+x[0]+x[2];
	else cout << x[2]*10+x[0]+x[1];
	return 0;
}
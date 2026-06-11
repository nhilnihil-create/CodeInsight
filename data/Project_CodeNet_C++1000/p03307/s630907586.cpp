#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main()
{
	int n, ans;
	cin >> n;
	if(n%2 == 0) ans = n;
	else ans=n*2;
	cout << ans;
	return 0;
}
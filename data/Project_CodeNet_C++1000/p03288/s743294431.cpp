#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main()
{
	int r;
	cin >> r;
	if(r < 1200) puts("ABC");
	else if(r>=1200 && r<2800) puts("ARC");
	else puts("AGC");
	return 0;
}
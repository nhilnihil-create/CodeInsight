#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m,x,y;cin >> n >> m >> x >> y;
	for(int i = 0;i < n;i++)
	{
		int xd;cin >> xd;x = max(x,xd);
	}
	for(int i = 0;i < m;i++)
	{
		int yd;cin >> yd;y = min(y,yd);
	}
	string k = "War";
	if(x < y)k = "No War";
	cout << k << endl;
}
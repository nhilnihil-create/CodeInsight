#include <bits/stdc++.h>
using namespace std;


int main() {
	int N, M, X,lcount=0, uCount=0,tmp;
	cin >> N >> M >> X;
	for (int i = 1; i <= M ; i++)
	{
		cin >> tmp;
		if (tmp>X)
		{
			uCount++;
		}
		else {
			lcount++;
		}
	}
	int ans = min(uCount, lcount);
	cout << ans << endl;
}
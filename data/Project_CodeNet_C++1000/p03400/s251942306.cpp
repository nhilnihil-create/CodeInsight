#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int n,d,x;
	cin >> n >> d >> x;
	rep(i,n)
	{
		int a;
		cin >> a;
		x += (d-1) / a + 1;
	}
	cout << x << endl;
	return 0;
}
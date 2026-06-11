#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int M = 10000001;


int main()
{
	int n, m;
	cin >> n >> m;
	int minn = M;
	int maxx = 0;
	rep(i, m) {
		int l, r;
		cin >> l >> r;
		minn = min(minn, r);
		maxx = max(maxx, l);
	}
	if (maxx > minn)
		cout << 0;
	else
		cout << minn - maxx + 1;

}

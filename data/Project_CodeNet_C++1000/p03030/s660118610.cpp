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
int Max = 10000000;
int main()
{
	int n;
	cin >> n;
	vector < pair<pair<string, int>, int>> aa(n);
	rep(i, n) {
		cin >> aa[i].first.first;
		cin >> aa[i].first.second;
		aa[i].first.second *= -1;
		aa[i].second = i + 1;
	}
	sort(aa.begin(), aa.end());
	rep(i, n) {
		cout << aa[i].second << endl;
	}
}
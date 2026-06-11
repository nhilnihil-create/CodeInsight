#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	s = '.' + s;
	int ans = n;
	for(int i = 2; i <= n; i++){
		if(s[i] != s[i-1]){
			int x = max(i-1,n-i+1);
			ans = min(ans,x);
		}
	}
	cout << ans << endl;

	return 0;
}
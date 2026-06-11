#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>
#include <complex>

using namespace std;

#define mod 1000000007


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int> > ans;
	if(n % 2 == 0){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(i + j != n + 1) ans.push_back(make_pair(i, j));
			}
		}
	} else {
		for(int i = 1; i <= n - 1; i++){
			for(int j = i + 1; j <= n - 1; j++){
				if(i + j != n) ans.push_back(make_pair(i, j));
			}
			ans.push_back(make_pair(i, n));
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
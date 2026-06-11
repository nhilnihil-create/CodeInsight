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

using namespace std;

#define mod 1000000007

int main()
{
	int n, k;
	cin >> n >> k;
	long long int a[1001];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<long long int> sums;
	for(int i = 0; i < n; i++){
		long long int nowsum = 0;
		for(int j = i; j < n; j++){
			nowsum += a[j];
			sums.push_back(nowsum);
		}
	}

	long long int ans = 0;
	vector<bool> ok(sums.size(), true);
	for(int i = 40; i >= 0; i--){
		long long int tmp = (long long int)1 << i;
		vector<bool> tmpok(sums.size(), true);
		int okcnt = 0;
		for(int j = 0; j < sums.size(); j++){
			tmpok[j] = ok[j] && ((sums[j] & tmp) > 0);
			if(tmpok[j]) okcnt++;
		}
		if(okcnt >= k){
			ans += tmp;
			ok = tmpok;
		}
	}
	cout << ans << endl;
}
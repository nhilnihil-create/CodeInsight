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
	int n;
	cin >> n;
	int c[200001];
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	long long int res[200001];
	long long int sumByColor[200001] = {};
	vector<int> prev(200001, -1);
	res[0] = 1;
	prev[c[0]] = 0;
	sumByColor[c[0]] = 1;
	for(int i = 1; i < n; i++){
		res[i] = res[i - 1];
		if(prev[c[i]] < i - 1){
			res[i] += sumByColor[c[i]];
			res[i] %= mod;
			sumByColor[c[i]] += res[i - 1];
			sumByColor[c[i]] %= mod;
		}
		prev[c[i]] = i;
		// cout << i << " " << res[i] << endl;
	}
	cout << res[n - 1] << endl;
}
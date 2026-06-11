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

bool isBigger(vector<int> v1, vector<int> v2)
{
	int cnt1 = accumulate(v1.begin(), v1.end(), 0);
	int cnt2 = accumulate(v2.begin(), v2.end(), 0);
	if(cnt1 > cnt2) return true;
	else if(cnt1 < cnt2) return false;
	else {
		for(int i = 9; i > 0; i--){
			if(v1[i] > v2[i]) return true;
			else if(v1[i] < v2[i]) return false;
		}
	}
	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int matchNum[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<bool> canuse(10, false);
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		canuse[a] = true;
	}
	vector<vector<int> > result(n + 1);
	result[0] = vector<int>(10, 0);
	for(int i = 0; i < n; i++){
		if(result[i].empty()) continue;
		for(int j = 1; j < 10; j++){
			if(!canuse[j] || i + matchNum[j] > n) continue;
			vector<int> tmp = result[i];
			tmp[j]++;
			if(isBigger(tmp, result[i + matchNum[j]])){
				result[i + matchNum[j]] = tmp;
			}
		}
	}
	for(int i = 9; i > 0; i--){
		for(int j = 0; j < result[n][i]; j++){
			cout << i;
		}
	}
	cout << endl;
}
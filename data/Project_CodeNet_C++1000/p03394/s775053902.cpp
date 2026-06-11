#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
queue<int> v2, v3, v6;

int main()
{
	int i, j, k;
	scanf("%d", &N);
	if (N == 3) {
		printf("2 5 63");
		return 0;
	}
	for (i = 2; i <= 30000; i+=2) {
		if (i % 3 == 0) v6.push(i);
		else if(i%3 == 1 || i%3 == 2) v2.push(i);
	}
	for (i = 3; i <= 30000; i += 2) {
		if (i % 3 == 0) v3.push(i);
	}
	int cnt = N / 2;
	vector<int> ans;
	ans.push_back(v3.front());
	v3.pop();
	ans.push_back(v3.front());
	v3.pop();
	cnt--;
	while (cnt--) {
		if (!v2.empty()) {
			ans.push_back(v2.front());
			v2.pop();
			ans.push_back(v2.front());
			v2.pop();
		}
		else if (!v3.empty()) {
			ans.push_back(v3.front());
			v3.pop();
			ans.push_back(v3.front());
			v3.pop();
		}
		else if (!v6.empty()) {
			ans.push_back(v6.front());
			v6.pop();
			ans.push_back(v6.front());
			v6.pop();
		}
	}
	if (N % 2) {
		ans.push_back(30000);
	}
	for (i = 0; i <ans.size(); ++i) {
		printf("%d ", ans[i]);
	}
	
}
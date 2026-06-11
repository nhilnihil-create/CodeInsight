#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> m[100001];
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		m[a].push_back(b);
	}
	for(int i = 1; i <= N; i++){
		sort(m[i].begin(), m[i].end());
	}
	
	int ans = 0;
	int leftCount = 0;
	int right = N+1;
	for(int i = 1; i <= N-1; i++){
		if(m[i].size() > 0){
			leftCount++;
			right = min(right, m[i][0]);
		}
		if(leftCount > 0 && right == i+1){
			ans++;
			right = N+1;
			leftCount = 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}
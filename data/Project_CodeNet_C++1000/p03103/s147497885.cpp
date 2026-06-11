#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

typedef std::pair<long long, long long> pr;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	std::vector<pr> v;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		long long a, b;
		cin >> a >> b;
		v.push_back(pr(a, b));
	}

	sort(v.begin(), v.end());

	long long ans = 0, m = 0;
	for(int i = 0; i < N; i++){
		long long a, b;
		a = v[i].first;
		b = min(M - m, v[i].second);
		ans += a * b;
		m += b;
		if(m >= M)
			break;
	}
	cout << ans << endl ;
	return 0;
}

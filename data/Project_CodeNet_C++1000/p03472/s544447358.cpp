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
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

int ubound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] <= b){
			s = m;
		}
		else{
			e = m;
		}
	}
	if(v[max(s - 1, 0)] > b) return max(s - 1, 0);
	else if(v[s] > b) return s;
	else if(v[min(s + 1, l - 1)] > b) return min(s + 1, l - 1);
	else return v.size();
}

LL N, H, W;
vector<LL> A, B;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> H;

	for(int i=0; i<N; i++){
		LL a, b;
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	LL m = A[A.size()-1];
	int pos = ubound(B, m);
	long long ans = 0;

	for(int j=B.size()-1; j>=pos; j--){
		H -= B[j];
		ans++;
		if(H <= 0){
			break;
		}
	}
	if(H > 0){
		ans += H / m;
		if((H % m) != 0){
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

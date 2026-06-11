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

int lbound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] >= b){
			e = m;
		}
		else{
			s = m;
		}
	}
	if(v[max(s - 1, 0)] >= b) return max(s - 1, 0);
	else if(v[s] >= b) return s;
	else if(v[min(s + 1, l - 1)] >= b) return min(s + 1, l - 1);
	else return v.size();
}

long long N, M;
vector<long long> A, B, C;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	for(int i=0; i<M; i++){
		long long b, c;
		cin >> b >> c;
		B.push_back(b);
		C.push_back(c);
	}
	for(int i=0; i<M; i++){
		if(i<M-1 && B[i+1]==N && C[i+1]>=C[i]) continue;
		long long b = B[i];
		long long c = C[i];
		long long k = (long long)lbound(A, c);
		long long u = min(k, b);
		if(k > 0){
			for(int j = u; j <= k - 1; j++){
				A[j - u] = A[j];
			}
			for(int j = k - u; j <= k - 1; j++){
				A[j] = c;
			}
		}
	}
	long long ans = 0;
	for(int i=0; i<N; i++){
		ans += A[i];
	}
	printf("%lld\n", ans);
	return 0;
}
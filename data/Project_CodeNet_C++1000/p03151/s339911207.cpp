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

typedef long long LL;
static LL INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	cin >> N;
	LL SA = 0, SB = 0;
	vector<LL> A, B, C;

	for(int i=0; i<N; i++){
		LL a; cin >> a;
		A.push_back(a);
		SA += a;
	}
	for(int i=0; i<N; i++){
		LL b; cin >> b;
		B.push_back(b);
		SB += b;
	}

	if(SA < SB){
		printf("-1\n");
		return 0;
	}

	LL s = 0;
	LL ans = 0;
	for(int i=0; i<N; i++){
		LL c = B[i] - A[i];
		C.push_back(c);
		if(c > 0){
			s += c;
			ans++;
		}
	}
	if(s == 0){
		printf("0\n");
		return 0;
	}
	sort(C.begin(), C.end());
	int i=0;
	map<int, int> M;
	while(true){
		if(C[i] < 0){
			LL w = min(s, (-1)*C[i]);
			s -= w;
			C[i] += w;
			if(M.count(i) == 0){
				M[i] = 1;
			}
			if(s == 0){
				break;
			}
		}
		if(C[i] >= 0){
			i++;
		}
	}
	ans += M.size();
	printf("%lld\n", ans);

	return 0;
}

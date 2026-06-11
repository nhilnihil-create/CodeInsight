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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	cin >> N;
	
	LL h = -1, n = -1, w = -1;
	int found = 0;
	for(h=1; h<=3500; h++){
		for(w=1; w<=3500; w++){
			LL A = N*h*w;
			LL B = 4*h*w - N*(h+w);
			if(B > 0 && A >= B && (A % B) == 0){
				n = A / B;
				found = 1;
				break;
			}
		}
		if(found == 1){
			break;
		}
	}
	printf("%lld %lld %lld\n", h, n, w);
	return 0;
}
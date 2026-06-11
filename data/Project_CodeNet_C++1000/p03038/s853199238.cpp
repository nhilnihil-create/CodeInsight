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

void addMapKey(map<long long, int> &m, long long k){
	if(m.count(k) == 0){
		m[k] = 1;
	}
	else{
		m[k]++;
	}
}

long long N, M;
map<long long, int> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		addMapKey(A, a);
	}

	for(int i=0; i<M; i++){
		long long b, c;
		cin >> b >> c;
		long long w = b;
		while(w > 0){
			long long u, v;
		    for(auto itr = A.begin(); itr != A.end(); itr++){
		    	u = itr->first;
		    	v = itr->second;
		    	if(u >= c) break;
		    	if(v <= w){
		    		A.erase(A.find(u));
		    		if(A.count(c)==0){
		    			A[c] = v;
		    		}
		    		else{
		    			A[c] += v;
		    		}
		    		w -= v;
		    	}
		    	else if(v > w){
		    		A[u] = v - w;
		    		if(A.count(c)==0){
		    			A[c] = w;
		    		}
		    		else{
		    			A[c] += w;
		    		}
		    		w = 0;
		    	}
		    	break;
		    }
			if(u >= c || w <= 0){
				break;
			}
		}
	}
	long long ans = 0;
	for(auto itr = A.begin(); itr != A.end(); itr++){
		long long u = itr->first;
		long long v = (long long)itr->second;
		ans += (u * v);
	}
	printf("%lld\n", ans);
	return 0;
}
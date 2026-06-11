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

int isPrime(LL p){
	if(p<=1) return 0;
	if(p==2 || p==3 || p==5 || p==7) return 1;
	if(p==4 || p==6 || p==8 || p==9) return 0;

	LL i;
	int ret = 1;
	for(i=2; i*i<=p; i++){
		if(p%i==0 && i!=p){
			ret = 0;
			break;
		}
	}
	return ret;
}

void factorize(long long N, map<long long, int> &mp){
	if(N == 1){
		return;
	}
	if(isPrime(N)){
		mp[N] += 1;
		return;
	}

	long long i = 2, n = N;
	for(i = 2; n != 1 && i < (N/2) + 1; i++){
		if((n % i)==0){
			if(isPrime(i)){
				int e = 0;
				long long u = n;
				while((u % i)==0){
					e++;
					u = u / i;
					n = u;
				}
				mp[i] = e;
				if(isPrime(n)){
					mp[n] = 1;
					break;
				}
			}
		}
	}
	return;
}


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	cin >> N;

	vector<map<long long, int>> V;
	map<long long, int> M;

	for(int i=1; i<=N; i++){
		map<long long, int> m;
		factorize((long long)i, m);
		V.push_back(m);
	}
	for(int i=0; i<V.size(); i++){
		auto m = V[i];
		for(auto itr = m.begin(); itr != m.end(); itr++){
			long long k = itr->first;
			int v = itr->second;
			if(M.count(k) == 0){
				M[k] = v;
			}
			else{
				M[k] += v;
			}
		}
	}

	int c3 = 0, c5 = 0, c15 = 0, c25 = 0,c75 = 0;
	for(auto itr = M.begin(); itr!= M.end(); itr++){
		long long k = itr->first;
		int v = itr->second;
		if(v >= 2){ c3++; }
		if(v >= 4){ c5++; }
		if(v >= 14){ c15++; }
		if(v >= 24){ c25++; }
		if(v >= 74){ c75++; }

	}

	if(c5 <= 1){
		printf("0\n");
		return 0;
	}

	long long ans = 0;
	if(c5 >= 2){
		ans += (c5*(c5-1)*(c5-2)/6)*3;
		ans += ((c3-c5) * (c5*(c5-1)/2));
	}
	if(c15 >= 1){
		ans += (c15*(c15-1));
		ans += ((c5-c15)*c15);
	}
	if(c25 >= 1){
		ans += (c25*(c25-1));
		ans += ((c3-c25)*c25);
	}
	if(c75 >= 1){
		ans += c75;
	}
	printf("%lld\n", ans);
	return 0;
}

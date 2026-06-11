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

LL N;
vector<LL> P;
vector<int> E;
LL ans = 0;

void dfs(vector<int> &v){
	int l = v.size();
	if(l == E.size()){
		LL d = 1;
		for(int i=0; i<P.size(); i++){
			LL u = 1;
			for(int j=1; j<=v[i]; j++){
				u *= P[i];
			}
			d *= u;
		}
		LL m = (N/d) - 1;
		if(m > 0 && d < m){
			ans += m;
		}
		return;
	}

	int e = E[l];
	for(int i=0; i<=e; i++){
		v.push_back(i);
		dfs(v);
		v.pop_back();
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	if(N == 1 || N==2){
		printf("0\n");
		return 0;
	}

	map<LL, int> M;
	factorize(N, M);
	for(auto itr = M.begin(); itr != M.end(); itr++){
		LL p = itr->first;
		int e = itr->second;
		P.push_back(p);
		E.push_back(e);
	}
	vector<int> v;
	dfs(v);
	printf("%lld\n", ans);
	return 0;
}

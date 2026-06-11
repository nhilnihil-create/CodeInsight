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

LL A, B, Q;
vector<LL> S, T;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> A >> B >> Q;

	for(int i=0; i<A; i++){
		LL s;
		cin >> s;
		S.push_back(s);
	}

	for(int i=0; i<B; i++){
		LL t;
		cin >> t;
		T.push_back(t);
	}
	
	sort(S.begin(), S.end());
	sort(T.begin(), T.end());

	for(int i=0; i<Q; i++){
		LL x;
		cin >> x;

		LL d1 = 0, d2 = 0, d3 = 0, d4 = 0;;
		int ps, pt;

		ps = lbound(S, x);
		pt = lbound(T, x);
		if( ps == S.size() || pt == T.size() ){
			d1 = INF;
		}
		else{
			ps = min(lbound(S, x), (int)S.size()-1);
			pt = min(lbound(T, x), (int)T.size()-1);
			d1 += max(abs(S[ps]-x), abs(T[pt]-x));
		}

		if(x < S[0] || x < T[0]){
			d2 = INF;
		}
		else{
			ps = max(lbound(S, x) - 1, 0);
			pt = max(lbound(T, x) - 1, 0);
			d2 += max(abs(S[ps]-x), abs(T[pt]-x));
		}

		ps = lbound(S, x);
		pt = lbound(T, x);
		if(ps == S.size() && pt == T.size()){
			d3 = INF;
		}
		else if(ps == S.size()){
			d3 += abs(T[pt] - x);
			d3 += abs(S[ps-1] - T[pt]);
		}
		else if(pt == T.size()){
			d3 += abs(S[ps] - x);
			d3 += abs(T[pt-1] - S[ps]);
		}
		else{
        	ps = min(lbound(S, x), (int)S.size()-1);
        	pt = min(lbound(T, x), (int)T.size()-1);
        	if(S[ps] < T[pt]){
        		d3 += abs(S[ps] - x);
        		int p = max(lbound(T, S[ps]) - 1, 0);
        		d3 += abs(T[p] - S[ps]);
        	}
        	else{
        		d3 += abs(T[pt] - x);
        		int p = max(lbound(S, T[pt]) - 1, 0);
        		d3 += abs(S[p] - T[pt]);
        	}
		}

		ps = lbound(S, x);
		pt = lbound(T, x);
		if(x < S[0] && x < T[0]){
			d4 = INF;
		}
		else if(x < S[0]){
			d4 += abs(T[pt-1] - x);
			d4 += abs(S[0] - T[pt-1]);
		}
		else if(x < T[0]){
			d4 += abs(S[ps-1] - x);
			d4 += abs(T[0] - S[ps-1]);
		}
		else{
        	ps = lbound(S, x) - 1;
        	pt = lbound(T, x) - 1;
        	if(S[ps] > T[pt]){
        		d4 += abs(S[ps] - x);
        		int p = min(lbound(T, S[ps]), (int)T.size() - 1);
        		d4 += abs(T[p] - S[ps]);
        	}
        	else{
        		d4 += abs(T[pt] - x);
        		int p = min(lbound(S, T[pt]), (int)S.size() - 1);
        		d4 += abs(S[p] - T[pt]);
        	}
		}

		LL ans = min(d1, min(d2, min(d3, d4)));
		printf("%lld\n", ans);
	}
	return 0;
}
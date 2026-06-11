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

LL N;
vector<string> S;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	LL ans = 0;
	// ca:Aで終わる文字列の個数, cb:Bで始まる文字列の個数, cab:Bで始まりかつAで終わる文字列の個数
	LL ca = 0, cb = 0, cab=0;

	for(int i=0; i<N; i++){
		string t, s;
		cin >> t;
		for(int j=0; j<t.size(); j++){
			if(t[j] == 'A' && j+1<t.size() && t[j+1] == 'B'){
				s.push_back('X');
				s.push_back('X');
				j++;
				ans++;
			}
			else{
				s.push_back(t[j]);
			}
		}
		S.push_back(s);
		if(s[s.size()-1] == 'A'){
			ca++;
		}
		if(s[0] == 'B'){
			cb++;
		}
		if(s[0] == 'B' && s[s.size()-1] == 'A'){
			cab++;
		}
	}

	LL u = ca - cab;
	LL v = cb - cab;
	LL w = cab;
	if(w == 0){
		ans += min(ca, cb);
	}
	else if(u == 0 && v == 0){
		ans += (w - 1);
	}
	else if(v == 0){
		if(w >= u){
			ans += (u + (w - u));
		}
		else{
			ans += w;
		}
	}
	else if(u == 0){
		if(w >= v){
			ans += (v + (w - v));

		}
		else{
			ans += w;
		}
	}
	else{
		if(u >= v){
			ans += v;
			LL d = u - v;
			ans += (d + (w - d));

		}
		else{
			ans += u;
			LL d = v - u;
			ans += (d + (w - d));
		}
	}
	printf("%lld\n", ans);
	return 0;
}

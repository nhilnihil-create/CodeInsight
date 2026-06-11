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

int N, A, B, C;
int l[10] = {0};

//合成魔法を使わない場合のmpを計算
int calcmp1(vector<int> v){
	int mp = 1000 * 3;
	int s[10] = {0}, t[10] = {0}, u[10] = {0};
	for(int i = 0; i <= v.size(); i++){
		s[i] = abs(v[i] - A);
		t[i] = abs(v[i] - B);
		u[i] = abs(v[i] - C);
	}

	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if(j == i) continue;
			for(int k = 0; k < v.size(); k++){
				if(k == i || k == j) continue;
				int v = s[i] + t[j] + u[k];
				if(v < mp){
					mp = v;
				}
			}
		}
	}
	return mp;
}

int bitCount(int b){
	int u = b;
	int ret = 0;
	while(u > 0){
		ret += u % 2;
		u = u / 2;
	}
	return ret;
}

//uを4進数で見たときの右からn桁目の値 (nは0から)
int getDigit4(int u, int n){
	int v = u;
	int ret = v % 4;
	for(int i = 0; i < n; i++){
		v = v / 4;
		ret = v % 4;
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> A >> B >> C;
	for(int i = 0; i < N; i++){
		int u;
		cin >> u ;
		l[i] = u;
	}

	//合成魔法を使わない場合の最小値
	vector<int> v;
	for(int i = 0; i < N; i++){
		v.push_back(l[i]);
	}
	int mp1 = calcmp1(v);

	//合成魔法を使う場合
	int ans = mp1;
	for(int e = 0; e < 65536; e++){ // 4**8 = 65536
		v.clear();
		vector<int> a, b, c, d;
		int s = 0, t = 0, u = 0;
		for(int i = 0; i < N; i++){
			int k = getDigit4(e, i);
			if(k == 0){ //Aを構成する竹にする
				a.push_back(l[i]);
				s += l[i];
			}
			else if(k == 1){ //Bを構成する竹にする
				b.push_back(l[i]);
				t += l[i];
			}
			else if(k == 2){ //Cを構成する竹にする
				c.push_back(l[i]);
				u += l[i];
			}
			else if(k == 3){ //それ以外
				d.push_back(l[i]);
				v.push_back(l[i]);
			}
		}
		if(s == 0 || t == 0 || u == 0){ continue; }
		v.push_back(s);
		v.push_back(t);
		v.push_back(u);
		int mp2 = max((int)a.size() - 1, 0) * 10 ; //合成魔法のmpは10
		mp2 += max((int)b.size() - 1, 0) * 10;
		mp2 += max((int)c.size() - 1, 0) * 10;
		mp2 += calcmp1(v);
		if(mp2 < ans){ ans = mp2; }
	}
	cout << ans << endl ;
	return 0;
}
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

int N, A, B, C;
int l[10] = {0};

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

	int ans = 1000000000;
	for(int e = 0; e < 65536; e++){ // 4**8 = 65536
		int a = 0, b = 0, c = 0, d = 0;
		int s = 0, t = 0, u = 0;
		for(int i = 0; i < N; i++){
			int k = getDigit4(e, i);
			if(k == 0){ //Aを構成する竹にする
				a++;
				s += l[i];
			}
			else if(k == 1){ //Bを構成する竹にする
				b++;
				t += l[i];
			}
			else if(k == 2){ //Cを構成する竹にする
				c++;
				u += l[i];
			}
			else if(k == 3){ //それ以外
				d++;
			}
		}
		if(s == 0 || t == 0 || u == 0){ continue; }
		int mp2 = max(a - 1, 0) * 10 ; //合成魔法のmpは10
		mp2 += max(b - 1, 0) * 10;
		mp2 += max(c - 1, 0) * 10;
		mp2 = mp2 + abs(s - A) + abs(t - B) + abs(u - C);
		if(mp2 < ans){ ans = mp2; }
	}
	cout << ans << endl ;
	return 0;
}
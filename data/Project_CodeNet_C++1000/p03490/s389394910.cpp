#include <bits/stdc++.h>
#define CR
using namespace std;

string s;
int x, y, f, d = 2;
vector<int> v[2];

bool sheidzleba_migeba_netavi(vector<int> v, int x) {
	int a[32004];
	for(int i = 0; i < 32004; ++i) a[i] = 0;
	a[16000] = 1;
	for(int j = 0; j < v.size(); ++j) {
		int t = v[j];
		for(int i = 0; i < 32004; ++i) {
			if(1) {
				if((i >= t && (a[i - t] & 1)) || (i + t < 32004 && (a[i + t] & 1))) {
					if(!a[i]) a[i] = 2;
					else a[i] = 3;
				}
			}
		}
		for(int i = 0; i < 32004; ++i) {
			if(a[i] >= 2) {
				a[i] = 1;
			} else {
				a[i] = 0;
			}
		}
	}
	return(bool)a[x + 16000];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef CR
	cin >> s >> x >> y;
	s += 'T';
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == 'F') {
			++f;
		} else {
			if(d == 2) {
				x -= f;
			} else {
				v[d].push_back(f);
			}
			f = 0;
			if(d) d = 0;
			else d = 1;
		}
	}
	#else
	while(1) {
		int n;
		x = 0;
		v[1].clear();
		cin >> n >> y;
		v[0].resize(n);
		for(int i = 0; i < n; ++i) cin >> v[0][i];
	#endif
	if(sheidzleba_migeba_netavi(v[0], y) && sheidzleba_migeba_netavi(v[1], x)) cout << "Yes" << endl;
	else cout << "No" << endl;
	#ifndef CR
	}
	#endif
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int niz[40];
map< pair<string, string>, int > m;
long long int sol = 0;

void rek(int x) {
	if (x == n) {
		
		string s1 = "", s2 = "";
		for (int i = n-1; i >= 0; i --) {
			if (niz[i] == 0) s1 += s[i];
			else s2 += s[i];
		}
		
		m[ make_pair(s1, s2) ] ++;
		return;
	}
	
	
	niz[x] = 0;
	rek(x+1);
	niz[x] = 1;
	rek(x+1);
}

void rj(int x) {
	if (x == 2*n) {
		
		string s1 = "", s2 = "";
		for (int i = n; i < 2*n; i ++) {
			if (niz[i] == 0) s1 += s[i];
			else s2 += s[i];
		}
		
		sol += m[ make_pair(s1, s2) ];
		return;
	}
	
	niz[x] = 0;
	rj(x+1);
	niz[x] = 1;
	rj(x+1);
}

int main () {

	cin >> n >> s;
	rek(0);
	rj(n);
	cout << sol;

	return 0;
}
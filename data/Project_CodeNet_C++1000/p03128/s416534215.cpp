#include <iostream>
#include <cstdio>
using namespace std;

int n, m, x[10];
int c[10]={0,2,5,5,4,5,6,3,7,6};
string d[10005];

string f(string p, string q) {
	if(p.size()>q.size() || p.size()==q.size() && p>q) return p;
	return q;
}

int main() {
	int i, j, t;
	cin >> n >> m;
	while(m--) {
		cin >> t;
		x[c[t]] = max(x[c[t]], t);
	}
	for(i=1; i<=n; i++) d[i] = ".";
	d[0] = "";
	for(i=2; i<=n; i++) {
		for(j=2; j<=8; j++) {
			t = x[j];
			if(!t || i<j || d[i-j]==".") continue;
			d[i] = f(d[i], d[i-j] + char(t+'0'));
		}
	}
	cout << d[n];
	return 0;
}
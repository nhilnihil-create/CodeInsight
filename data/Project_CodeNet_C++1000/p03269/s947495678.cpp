#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 100009;

lli l;
lli n;
lli m;
lli s;
lli bit = 1;
mat g;
mat w;



int main(){
	cin >> l;
	while(bit <= l) bit <<= 1,n++;
	g = mat(n);
	w = mat(n);
	bit = 1;
	for(lli i = n-1;i > 0;i--){
		g[i].push_back(i+1);
		w[i].push_back(bit);
		g[i].push_back(i+1);
		w[i].push_back(0);
		m += 2;
		if((l&bit) != 0){
			l -= bit;
			g[1].push_back(i+1);
			w[1].push_back(l);
			m++;
		}
		bit <<= 1;

	}
	cout << n << " " << m << endl;
	for(lli i = 1;i < n;i++){
		for(lli j = 0;j < g[i].size();j++){
			cout << i << " " << g[i][j] << " " << w[i][j] << endl;
		}
	}



}

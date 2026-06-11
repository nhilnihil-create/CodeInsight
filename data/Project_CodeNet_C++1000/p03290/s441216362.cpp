#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 12;
const int MAX_V = 1e7+1;
int D, G;
int p[MAX_N];
int c[MAX_N];

int go(int bf)
{
	int pt = 0, pb = 0;
	for(int i=0;i<D;++i)if(bf>>i&1){
		pt += p[i+1]*100*(i+1)+c[i+1];
		pb += p[i+1];
	}
	for(int i=D-1;pt<G&&i>=0;--i)if(!(bf>>i&1)){
		int diff = G-pt;
		int point = 100*(i+1);
		int so = min(p[i+1]-1, (diff+point-1)/point);
		pt += so*point;
		pb += so;
	}
	if(pt >= G) return pb;
	else return -1;
}

void solve()
{
	int ans = 2000;
	for(int b=0;b<(1<<D);++b){
		int best = go(b);
		if(best != -1) ans = min(ans, best);
	}
	cout << ans << '\n';
}

int main()
{
	cin >> D >> G;
	for(int i=1;i<=D;++i) cin >> p[i] >> c[i];
	solve();
	return 0;
}
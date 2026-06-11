// D - Recording
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	int N,C; cin>>N>>C;
	vector<vi> tv(100000, vi(C, 0));
	while(N--){
		int s,t,c; cin>>s>>t>>c; --c;
		rp(i, s-1, t) tv[i][c] = 1;
	}
	int ans = 0;
	rp(z, 0, tv.size()){
		int s = 0; rp(c, 0, tv[z].size()) s += tv[z][c];
		ans = max(ans, s);
	}
	cout<< ans <<endl;
}

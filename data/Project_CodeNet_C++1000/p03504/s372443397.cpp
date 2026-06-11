// D - Recording
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main(){
	int N,C; cin>>N>>C;
	vector<vi> tv(100000, vi(C, 0));
	int mx_t = 0;
	while(N--){
		int s,t,c; cin>>s>>t>>c; --c;
		for(int i=s-1; i<t; ++i) tv[i][c] = 1;
		mx_t = max(mx_t, t);
	}
	int ans = 0;
	for(int t=0; t<mx_t; ++t){
		int s = 0; for(auto c:tv[t]) s += c;
		ans = max(ans, s);
	}
	cout<< ans <<endl;
}

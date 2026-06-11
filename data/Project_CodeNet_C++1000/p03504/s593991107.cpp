// D - Recording
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main(){
	int N,C; cin>>N>>C;
	vector<vi> tv(100000, vi(C, 0));
	while(N--){
		int s,t,c; cin>>s>>t>>c; --c;
		for(int i=s-1; i<t; ++i) tv[i][c] = 1;
	}
	int ans = 0;
	for(auto z:tv){
		int s = 0; for(auto c:z) s += c;
		ans = max(ans, s);
	}
	cout<< ans <<endl;
}

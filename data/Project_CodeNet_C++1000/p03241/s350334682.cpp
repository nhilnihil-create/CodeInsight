#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	LL N, M;
	cin >> N >> M;
	vector<LL> p;
	for(LL i=1; i*i<=M; i++){
		if(M%i==0){
			p.emplace_back(i);
			p.emplace_back(M/i);
		}
	}
	LL ans=1;
	rep(i,p.size()){
		if(p[i]*N<=M) ans=max(ans,p[i]);
	}
	cout << ans << endl;

	return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	LL N, M;
	cin >> N >> M;
	vector<LL> A(N), sum(N+1);
	rep(i,N) cin >> A[i];
	rep(i,N) sum[i+1]=sum[i]+A[i];
	rep(i,N) sum[i+1]%=M;
	map<LL,LL> m;
	rep(i,N+1) m[sum[i]]++;
	LL ans=0;
	for(auto itr:m) ans+=itr.second*(itr.second-1)/2;
	cout << ans << endl;

	return 0;
}
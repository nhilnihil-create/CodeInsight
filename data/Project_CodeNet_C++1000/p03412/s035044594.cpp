// http://kmjp.hatenablog.jp/entry/2018/03/20/0900

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted

int main(){

	ll N,ans=0;
	cin >> N;
	vector<ll> A(N),B(N);
	FOR(i,0,N)cin>>A[i];
	FOR(i,0,N)cin>>B[i];
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	FOR(i,0,29){
		vector<ll> C(N);
		FOR(x,0,N)C[x] = B[x]%(1<<(i+1));
		sort(C.begin(),C.end());
		ll tot = 0;
		FOR(x,0,N){
			ll y = A[x]%(1<<(i+1));
			tot += POSL(C,(1<<(i+1))-y)-POSL(C,(1<<(i))-y);
			tot += POSL(C,(1<<(i+2))-y)-POSL(C,3*(1<<(i))-y);
		}
		if(tot%2) ans += 1<<i;
	}
	cout << ans << endl;

}
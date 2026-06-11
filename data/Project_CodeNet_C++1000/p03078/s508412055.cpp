#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1006;
int X,Y,Z,K;
ll A[MAX_N],B[MAX_N],C[MAX_N];

void solve()
{
	sort(A,A+X,greater<ll>());
	sort(B,B+Y,greater<ll>());
	sort(C,C+Z,greater<ll>());
	vector<ll> v;
	for(int i=0;i<X;++i)for(int j=0;j<Y;++j){
		v.push_back(A[i]+B[j]);
	}
	sort(v.rbegin(), v.rend());
	vector<ll> ans;
	for(int i=0;i<min((int)v.size(), K);++i){
		for(int j=0;j<Z;++j) ans.push_back(v[i]+C[j]);
	}
	sort(ans.rbegin(),ans.rend());
	for(int i=0;i<K;++i) cout<<ans[i]<<'\n';
}

int main()
{
	cin >> X >> Y >> Z >> K;
	for(int i=0;i<X;++i) cin >> A[i];
	for(int i=0;i<Y;++i) cin >> B[i];
	for(int i=0;i<Z;++i) cin >> C[i];
	solve();
	return 0;
}
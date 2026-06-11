#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+10;
int N, A[MAX_N];
int occ[25];

void solve()
{
	ll ans = 0;
	memset(occ,-1,sizeof(occ));
	int i = 0;
	for(int j=0;j<N;++j){
		int a = A[j];
		for(int k=0;k<25;++k)if(a>>k&1){
			if(occ[k]!=-1){
				i=max(i, occ[k]+1);
			}
			occ[k]=j;
		}
		ans+=(j-i+1);
	}
	cout << ans << '\n';
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i)cin >> A[i];
	solve();
	return 0;
}
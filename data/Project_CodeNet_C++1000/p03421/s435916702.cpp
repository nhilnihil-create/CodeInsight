#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define se second
#define fi first
#define pb push_back

int main(){

	//freopen("in.txt","r",stdin);

	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);

	if(a + b - 1 > n || a * 1LL * b < n) return puts("-1"), 0;

	vector<vector<int> > v;
	v.resize(a);
	for(int i=n - a + 1,j=0;i <= n;i++, j++){
		v[j].pb(i);
	}

	int cb=0,in=0;
	while(cb < n - a){
		cb++;
		int mx=min(cb + (b - 2),n - a);
		for(int i=mx;i >= cb;i--){
			v[in].pb(i);
		}
		in++;
		cb=mx;
	}
	for(int i=0;i < v.size();i++){
		for(int j=0;j < v[i].size();j++){
			printf("%d ",v[i][j]);
		}
	}

	return 0;
}

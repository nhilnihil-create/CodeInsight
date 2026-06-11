#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const ll inf=1e18;
const int N=16;
int a[N][N];
int n;
ll price[1<<N];
ll dp[1<<N];

ll go(int done,int thismask,int p){
	if(!p&&~dp[done])return dp[done];
	if(p==n)return price[thismask]+(thismask?go(done|thismask,0,0):0);
	return dp[done]=max(go(done,thismask,p+1),(done&(1<<p))?0:go(done,thismask|(1<<p),p+1));
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	for(int i=1;i<(1<<n);++i)
		for(int j=0;j<n;++j)
			for(int k=j+1;k<n;++k)
				if(((1<<j)&i)&&((1<<k)&i))
					price[i]+=a[j][k];
	memset(dp,-1,sizeof(dp));
	dp[(1<<n)-1]=0;
	cout<<go(0,0,0)<<endl;
}

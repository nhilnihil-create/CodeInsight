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

const int N=3030;
int n,m;
ll dp[N][N];
string s,t;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>s>>t;
	n=s.size(),m=t.size();
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j){
			if(i<n&&j<m&&s[i]==t[j])dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
//	for(int i=0;i<=n;++i,cout<<endl)
//		for(int j=0;j<=m;++j)
//			cout<<dp[i][j]<<" ";
	int i=n,j=m,cnt;
	string res;
	while(cnt=dp[i][j]){
		while(i&&dp[i-1][j]==cnt)--i;
		while(j&&dp[i][j-1]==cnt)--j;
		--i;--j;
		res.push_back(s[i]);
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
}

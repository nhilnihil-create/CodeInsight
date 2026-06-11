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

const int N=3030,mod=1e9+7;
string s;
ll dp[N][N],pref[N][N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>s;
	for(int i=1;i<=n;++i)pref[1][i]=1;
	dp[1][1]=1;
	for(int len=2;len<=n;++len){
		for(int newlast=1;newlast<=len;++newlast){
			int l,r;
			if(s[len-2]=='<'){
				l=0;r=newlast-1;
			}
			else{
				l=newlast-1;r=n;
			}
			dp[len][newlast]=(mod+pref[len-1][r]-pref[len-1][l])%mod;
		}
		for(int i=1;i<=n;++i)pref[len][i]=(dp[len][i]+pref[len][i-1])%mod;
	}
	cout<<pref[n][n]<<endl;
}

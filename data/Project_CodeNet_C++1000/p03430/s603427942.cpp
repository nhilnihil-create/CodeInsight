#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
string s;
int lim,n;
int mn[305][305][26],mx[305][305][26],dp[305][305][155];
int rec(int a,int b,int c){
	if(dp[a][b][c] >= 0) return dp[a][b][c];
	if(a>b) return 0;
	int &ret = dp[a][b][c];
	int len = (a==b?1:2);
	if(c) ret=max(ret,rec(a+1,b-1,c-1)+len);
	for(int k=0;k<26;k++){
		if(mx[a][b][k] == -INF) continue;
		int d = mn[a][b][k]-a;
		int e = b-mx[a][b][k];
		d = min(d,e);
		int len = (mn[a][b][k]==mx[a][b][k]?1:2);
		ret = max(ret,len+rec(mn[a][b][k]+1,mx[a][b][k]-1,c-min(c,d))+min(c,d)*2);
	}
	return ret;
}
int main(){
	cin>>s>>lim;
	n = s.size();
	rep(a,305)rep(b,305)rep(c,26){
		mn[a][b][c] = INF;
		mx[a][b][c] = -INF;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				mx[i][j][s[k]-'a'] = max(mx[i][j][s[k]-'a'],k);
				mn[i][j][s[k]-'a'] = min(mn[i][j][s[k]-'a'],k);
			}
		}
	}
	lim = min(n/2+1,lim);
	rep(a,305)rep(b,305)rep(c,155)dp[a][b][c] = -INF;
	cout << rec(0,n-1,lim) << endl;
}
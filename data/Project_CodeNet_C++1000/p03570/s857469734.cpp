#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<62;
const double pi=acos(-1);
const double eps=1e-7;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

const int M=26;

void f(int x){
	for(int i=0;i<M;i++){
		if(x&1<<i) cout<<1;
		else cout<<0;
	}
	cout<<endl;
}

int n;
string s;

int main(){
	cin>>s;
	n=s.size();
	vi a(M);
	vvi dp(n+1,vi(M+1,inf));
	map<int,int> m;
	int tmp=0,res=inf,S=0;
	for(int i=0;i<n;i++) a[s[i]-'a']++;
	for(int i=0;i<M;i++) tmp+=a[i]%2;
	if(tmp<=1){
		cout<<1<<endl;
		return 0;
	}
	dp[0][M]=0;
	m[0]=0;
	for(int i=0;i<n;i++){
		int c=s[i]-'a',mn=inf;
		S^=1<<c;
		dp[i+1][M]=dp[i][c];
		for(int j=0;j<M;j++){
			int T=S^(1<<j);
			if(m.find(T)!=m.end()){
				int I=m[T];
				for(int k=0;k<=M;k++) dp[i+1][j]=min(dp[i+1][j],dp[I][k]+(k!=M||I==0?1:0));
			}
			mn=min(mn,dp[i][j]);
		}
//		if(i==1) cout<<mn<<endl;
		dp[i+1][c]=min(dp[i+1][c],mn+1);
		m[S]=i+1;
	}
	for(int i=0;i<=M;i++) res=min(res,dp[n][i]);
	cout<<res<<endl;
//	cout<<dp[6][23]<<endl;
//	cout<<dp[1][0]<<endl;
}
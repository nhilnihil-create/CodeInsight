/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[20002][2002];
int N;
struct data{
	int w,s,v;
}a[1002];
bool cmp(data A,data B){
	return A.s+A.w<B.s+B.w;
}
int main(){
	fastio;
	cin>>N;
	rb(i,1,N)
		cin>>a[i].w>>a[i].s>>a[i].v;
	sort(a+1,a+1+N,cmp);
	LL res=0;
	rb(i,1,N){
		rb(W,0,20000){
			dp[W][i]=dp[W][i-1];
			if(a[i].w<=W&&a[i].s>=W-a[i].w){
				dp[W][i]=max(dp[W][i],dp[W-a[i].w][i-1]+a[i].v);
			}
			res=max(res,dp[W][i]);
		}
	}
	cout<<res<<endl;
	return 0;
}

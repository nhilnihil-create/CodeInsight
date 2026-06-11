#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1 << " | ";__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

const int MOD = 1e9 + 7;
int power(int a,int n){
	int r=1;
	while( n ){
		if( n&1 ){
			r*=a;
			r%=MOD;
		}
		a*=a;
		a%=MOD;
		n>>=1;
	}
	return r;
}

struct box{
	int w,s,v;
};
bool cmp(box a,box b){
	return a.w + a.s > b.w + b.s;
}
int32_t main()
{
   IOS
   const int MXS=2e4+5;// 2* s :  j-s  to be updated
   vector<int>dp(MXS+1);
   int n;cin>>n;
   vector<box>a(n);
   for(int i=0;i<n;i++)
   cin>>a[i].w>>a[i].s>>a[i].v;
   sort(a.begin(),a.end(),cmp);
   for(int i=0;i<n;i++)
   {
	   int w,s,v;
	   w=a[i].w;
	   s=a[i].s;
	   v=a[i].v;
	   vector<int>dp2=dp;
	   for(int j=0;j<=MXS;j++)
	   {
		   int k = min(j-w,s);
		   if( k >= 0 )
		   {
			   dp2[k]=max(dp2[k],dp[j]+v);
		   }
	   }
	   dp=dp2;
   }
   int mxv=0;
   for(int i=0;i<=MXS;i++)
   mxv=max(mxv,dp[i]);
   cout << mxv << endl;
  
}

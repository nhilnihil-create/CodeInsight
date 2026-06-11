#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int n,dp[1009][10009];
pair <pair<int,int>,int> v[1009];
bool comp(pair <pair<int,int>,int> a,pair <pair<int,int>,int> b){
	int w1=a.f.f,w2=b.f.f;
	int s1=a.f.s,s2=b.f.s;
	if(s1+w1==s2+w2)
		return s1>s2;
	return (s1+w1>s2+w2);
	// if(s1>=w2 and s2>=w1)return (s1-w2>s2-w1);
	// if(s1<w2 and s2<w1)return (s1>s2);
	// if(s1>=w2 and s2<w1)return 1;
	// else return 0;
}
int f(int i,int c){
	if(i==n)return 0;
	if(dp[i][c]!=-1)
		return dp[i][c];
	dp[i][c]=f(i+1,c);
	if(v[i].f.f<=c)
		dp[i][c]=max(dp[i][c],v[i].s+f(i+1,min(c-v[i].f.f,v[i].f.s)));
	return dp[i][c];
}
int32_t main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n;
	int sum=0;
	for(int i=0;i<n;i++){
		cin >> v[i].f.f >> v[i].f.s >> v[i].s;
		sum+=v[i].f.f;
	}
	sort(v,v+n,comp);
	memset(dp,-1,sizeof(long long)*1009*10009);
	int m=0;
	for(int i=0;i<n;i++){
		m=max(v[i].s+f(i+1,v[i].f.s),m);
	}
	cout << m << endl;
}

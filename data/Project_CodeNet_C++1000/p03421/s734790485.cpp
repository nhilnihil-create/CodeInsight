#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define INF 10000000000000000
#define rep(i,n) for(int i=0;i<n;i++)
int n,a,b;
signed main(){
	cin>>n>>a>>b;
	if(a+b-1>n||a*b<n){
		puts("-1");
		return 0;
	}
	int x=n-a;
	for(int i=n-a+1;i<=n;i++)cout<<i<<" ";
	for(int i=2;i<=b;i++){
		int t=min(x-b+i,a);
		for(int j=x-t+1;j<=x;j++)cout<<j<<" ";
		x-=t;
	}
	return 0;
}

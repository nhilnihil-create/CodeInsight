#include<bits/stdc++.h>
#define int long long
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define mod 1000000007
#define P pair<int,int>
using namespace std;
signed main(){
	int n,a,b,c,d,ans=0;
	cin>>n>>a>>b;
	f(i,n){
		cin>>c>>d;
		if(a<=c&&b<=d) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

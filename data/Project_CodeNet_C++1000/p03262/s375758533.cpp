#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}

int main(){

	int n,k;
	cin>>n>>k;
	int x[n+1];
	rep(i,n)cin>>x[i];
	x[n]=k;
	sort(x,x+n+1);

	int ans=x[1]-x[0];
	rep(i,n){
		ans=gcd(ans,x[i+1]-x[i]);
	}
	cout<<ans<<endl;

	return 0;
}

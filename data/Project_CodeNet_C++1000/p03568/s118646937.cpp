#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979
using ll = long long;
using P = pair<int,int>;

ll divisor=1e9+7;
int main(){
	int n;
	cin>>n;
	int a[n];
	rep(i,n){
		cin>>a[i];
	}
	ll coun=1;
	ll ans=1;
	rep(i,n){
		if(a[i]%2==0)coun*=2;
		ans*=3;
	}
	puts(ans-coun);
}
#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<ll>a(n+1);
	a[0]=2,a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	cout<<a[n];
	
	
}
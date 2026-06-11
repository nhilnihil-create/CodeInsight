#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int f(int x){
	int c=0;
	while(x)c+=x%10,x/=10;
	return c;
}

int main(){
	int n,a,b,ans=0;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		if(f(i)>=a && f(i)<=b)ans+=i;
	}
	cout<<ans;
}




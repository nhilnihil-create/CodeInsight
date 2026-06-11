#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ll n,m;
	scanf("%lld%lld",&n,&m);
	if(m%n==0){
		printf("%lld",n+m);
	}	
	else{
		printf("%lld",m-n);
	}
}

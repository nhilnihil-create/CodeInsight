#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
int n,a,b;
int main(){
	cin >> n >> a >> b;
	if((a-b)%2)puts("Borys");
	else puts("Alice");
	return 0;
}
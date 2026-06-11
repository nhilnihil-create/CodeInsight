#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	if(n==m && n==1) cout<<1;
	else if(n==1 || m==1) cout<<n*m-2;
	else cout<<(n-2)*(m-2);
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	if(n>m){
		cout<<n+n-1;
	}else if(n==m){
		cout<<n+n;
	}else cout<<m+m-1;
	return 0;
}
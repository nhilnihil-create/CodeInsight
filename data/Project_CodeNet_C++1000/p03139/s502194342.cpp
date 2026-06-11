/*
Web:AtCoder
User:sunyx
Prob:A-Subscribers
Method:小学Math 
*/
#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main() {
	cin>>n>>a>>b;
	cout<<min(a,b)<<' ';
	int p=a+b;
	if (p<=n) cout<<0;
	else cout<<p-n;
	return 0;
}
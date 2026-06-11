#include<bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int n=a;
	if(c>a) {
		a=c;
	}
	if(b>a) {
		a=b;
	}
	if(c<b) {
		b=c;
	}
	if(n<b) {
		b=n;
	}
	cout<<a-b;
	return 0;
}
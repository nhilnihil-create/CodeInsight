#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main(){
	fast_io;
	int a,b;
	cin>>a>>b;
	if(a==b) cout<<2*a;
	else cout<<max(a,b)*2-1;
	return 0;
}
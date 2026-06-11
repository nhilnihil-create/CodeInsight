#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;

	cin>>a>>b;

	auto ans = max({a+b, a-b, a*b});

	cout<<ans<<'\n';

	return 0;
}
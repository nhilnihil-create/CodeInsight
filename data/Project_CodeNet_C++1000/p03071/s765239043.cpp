#include <bits/stdc++.h>

using namespace std;

int ans;
int main(){
	int a,b;
	cin>>a>>b;
	cout<<max(a,b)+max(max(a,b)-1,min(a,b));
}
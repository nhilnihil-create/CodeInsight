#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int a,b; cin>>a>>b;
	if(a==b) cout<<a*2<<endl;
	else cout<<max(a,b)*2-1<<endl;
	
}
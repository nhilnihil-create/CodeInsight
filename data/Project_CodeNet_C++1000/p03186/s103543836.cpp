#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c;
	if(a+b>=c) return cout<<b+c<<endl,0;
	else return cout<<a+b+b+1<<endl,0; 
}
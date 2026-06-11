#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main(){
	ll a,b,c; cin>>a>>b>>c;
	if(a+b+1>=c) cout<<b+c;
	else cout<<b+a+b+1;
}

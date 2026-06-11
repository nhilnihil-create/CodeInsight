#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c; cin>>a>>b>>c;
	if(a+b>=c) cout<<c+b<<endl;
	else cout<<a+2*b+1<<endl;
}
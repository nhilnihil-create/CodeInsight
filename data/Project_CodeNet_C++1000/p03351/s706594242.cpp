#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	if(abs(a-b)<=d&&abs(b-c)<=d||abs(a-c)<=d) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
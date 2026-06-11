#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c; cin>>a>>b>>c;
	if(c>a&&c<b) cout<<"Yes"<<endl;
	else if(c>b&&c<a) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
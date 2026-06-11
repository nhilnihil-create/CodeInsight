#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	char x,y; cin>>x>>y;
	if(x>y) cout<<'>'<<endl;
	else if(x<y) cout<<'<'<<endl;
	else cout<<'='<<endl;
}
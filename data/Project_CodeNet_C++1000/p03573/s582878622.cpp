#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc; tc=1;
	while(tc--){
		int a,b,c; cin>>a>>b>>c;
		if(a == b) cout<<c;
		if(a == c) cout<<b;
		if(b == c) cout<<a;
		cout<<endl;
	}
}
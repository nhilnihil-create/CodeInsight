#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,k; cin>>a>>b>>k;
	bool t{1};
	while(k--){
		if(t){
			if(a%2) a--;
			a>>=1;
			b+=a;
		}
		else{
			if(b%2) b--;
			b>>=1;
			a+=b;
		}
		t^=1;
	}
	cout<<a<<' '<<b<<endl;
}

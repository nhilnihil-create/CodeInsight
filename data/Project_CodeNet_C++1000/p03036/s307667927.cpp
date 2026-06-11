#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int r,d,x; cin>>r>>d>>x;
	ll op = x*1ll;
	for(int i=0; i<10; i++){
		op = r*op-d; 
		cout<<op<<endl;
	}
	return 0;
}

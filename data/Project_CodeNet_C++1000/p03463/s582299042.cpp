#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a,b;
	cin>>n>>a>>b;
	if(n==2){
		cout<<"Borys"<<endl;
	}else if((a%2==0 && b%2==0) || (a%2==1 && b%2==1)){
		cout<<"Alice"<<endl;
	}else{
		cout<<"Borys"<<endl;
	}
	return 0;
}

#define _USE_MATH_DEFINES
#include<iostream>


using ll = long long;

using namespace std;


int main() {
	int n,y;
	cin>>n>>y;
	bool ok=false;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			int k=n-i-j;
			if(10000*i+5000*j+1000*k==y){
				cout<<i<<" "<<j<<" "<<k<<endl;
				ok=true;
				break;
			}
			if(ok)break;
		}
		if(ok)break;
	}
	if(!ok)cout<<"-1 -1 -1"<<endl;
	return 0;
}
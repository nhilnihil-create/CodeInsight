#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int x; cin>>x;
	int ans=1;
	for(int i=1; i<x; i++){
		for(int j=2; j<x; j++){
			int y=pow(i,j);
			if(y<=x) ans=max(ans,y);
		}
	}
	cout<<ans<<endl;
}
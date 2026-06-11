#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,d,x; cin>>n>>d>>x;
	int ans=0;
	rep(i,n){
		int a; cin>>a;
		int j=1;
		while(1){
			if(a*j+1>d) break;
			ans++;
			j++;
		}
	}
	cout<<ans+n+x<<endl;
}
#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	int ans = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			int t = n-i*r-j*g;
			if(t >= 0 && t % b == 0){
				ans++;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}

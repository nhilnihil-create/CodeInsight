#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t;
  	cin >> n >> t;
  	long ans=1e9+7;
  	for(int i=0;i<n;i++){
    	long a,b;
      	cin >> a >> b;
      	if(b<=t)ans=min(ans,a);
    }
  	if(ans==1e9+7)cout << "TLE";
  	else cout << ans;
}

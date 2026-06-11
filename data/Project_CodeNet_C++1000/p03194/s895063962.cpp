#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(n>40){
    	cout << 1;
    	return 0;
	}
	if(n==1){
		cout << m;
		return 0;
	}
	for(int i=1;i<1000005;i++){
		ll x=1;
		for(int j=0;j<n;j++){
			x*=i;
			if(x>m){
				cout << ans;
				return 0;
			}
		}
		if(m%x==0)ans=i;
	}
    return 0;
}
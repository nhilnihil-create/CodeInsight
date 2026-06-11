#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

char a[302][302],b[302][302];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	ll ans=0;
	for(ll B=0;B<n;B++){
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				ll nex=j+B;
				nex%=n;
				b[i][nex]=a[i][j];
			}
		}
		bool ch=true;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				if(b[i][j]!=b[j][i]){
					ch=false;
				}
			}
		}
		if(ch){
			ans+=n;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}
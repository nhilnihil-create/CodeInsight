#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	for(ll i=i;i<=3500;i++){
		for(ll j=1;j<=3500;j++){
			ll up=n*i*j;
			ll down=4*i*j-n*i-n*j;
			if(down<=0){
				continue;
			}
			if(up%down==0){
				if(up/down!=0){
				cout << i<< " "<< j<<" "<<up/down;
				return 0;
				}
			}
		}
	}
	// your code goes here
	return 0;
}
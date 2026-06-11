#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	cout << (n-1)*n/2-n/2<<endl;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(n%2==0){
				if((n-1-j)==i){
					continue;
				}
			}
			else{
				if((n-2-j)==i){
					continue;
				}
			}
			cout << i+1<<" "<<j+1<<endl;
		}
	}
	// your code goes here
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll l=0;
	string L;
	cout << 0<<endl;
	cin >>L;
	if(L=="Vacant"){
		return 0;
	}
	ll next=(n-l)/2;
	string ne;
	while(true){
		cout << next<<endl;
		cin>>ne;
		if(ne=="Vacant"){
			return 0;
		}
		if(ne==L){
			if((l-next)%2==0){
				l=next;
				L=ne;
			}
			else{
				n=next;
			}
		}
		else{
			if((l-next)%2==0){
				n=next;
			}
			else{
				l=next;
				L=ne;
			}
		}
		next=(n-l)/2+l;
	}
	// your code goes here
	return 0;
}
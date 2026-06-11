#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll cnt=0;
	vector<ll>a;
	a.push_back(2);
	for(ll i=3;;i++){
		bool ch=true;
			for(auto itr=a.begin();itr!=a.end();itr++){
				if(i%*itr==0){
					ch=false;
				}
			}
			if(ch){
				if(i%5==1){
				cout << i<<" ";
				cnt++;
				}
				a.push_back(i);
			}
		if(cnt==n){
			return 0;
		}
	}
	// your code goes here
	return 0;
}
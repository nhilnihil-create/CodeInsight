#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	if(n < a+b-1 || a*b < n){
		puts("-1");
		return 0;
	}
	
	vector<ll> ret;
	for(int i = b ; i >= 1 ; i --){
		ret.push_back(i);
	}
	for(int i = 2 ; i <= a ; i ++){
		ll x = min( b , (ll)(n-ret.size()-(a-i)) );
		ll y = ret.size();
		for(int j = x ; j >= 1 ; j --){
			ret.push_back(y+j);
		}
	}
	for(int i = 0 ; i < ret.size() ; i ++){
		printf("%lld%c",ret[i],(i+1==ret.size())?'\n':' ');
	}
}
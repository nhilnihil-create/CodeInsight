#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n;
	cin>>n;
	if(n == 0){
		cout<<0<<endl;
	}
	string ret = "";
	while(n != 0){
		if(n%2 != 0){
			ret += '1';
			n = (1 - n)/2;
		}else{
			ret += '0';
			n = -n/2;
		}
	}
	reverse(ret.begin(), ret.end());
	cout<<ret<<endl;

	return 0;
}
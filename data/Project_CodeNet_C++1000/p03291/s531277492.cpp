#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int a[114514],ab[114514],abc[114514];
int modpow(int x,int k){
	// x ^ k mod inf
	int res = 1;
	while(k>=1){
		if(k%2)res = (res*x)%inf;
		x = (x*x)%inf;
		k >>=1;
	}
	return res;
}
signed main(){
	string str;
	cin>>str;
	int ht = 0;
	int n = str.size();
	for(int i=1;i<=n;i++){
		if( str[i-1] == 'A' ){
			a[i] = a[i-1] + modpow(3,ht);
			ab[i] = ab[i-1];
			abc[i] = abc[i-1];
		}
		if( str[i-1] == 'B' ){
			a[i] = a[i-1];
			ab[i] = ab[i-1] + a[i-1];
			abc[i] = abc[i-1];
		}
		if( str[i-1] == 'C'){
			a[i] = a[i-1];
			ab[i] = ab[i-1];
			abc[i] = abc[i-1] + ab[i-1];
		}
		if( str[i-1] == '?'){
			a[i] = 3 * a[i-1] + modpow(3,ht);
			ab[i] = 3 * ab[i-1] + a[i-1];
			abc[i] = 3 * abc[i-1] + ab[i-1];
			ht++;
		}
		a[i] %= inf;
		ab[i] %= inf;
		abc[i] %= inf;
	}
	cout<<abc[n]<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli k, a, b;

int main(void){
	cin >> k >> a >> b;
	if(k <= a){
		cout << 1+k << endl;
		return 0;
	}
	lli ans = 1;
	if(b < 2+a){
		ans+=a+1;
	}else{
		ans=b;
	}
	k=max(0LL, k-a-1);
	ans += (k/2*max(2LL, b-a) + k%2);
	cout << ans << endl;
	return 0;
}

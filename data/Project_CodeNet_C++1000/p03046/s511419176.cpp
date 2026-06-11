#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long M=100000007;
ll ans[M],n,k;
int main(){
	cin >> n >> k;
	if(k >= (1<<n)){cout<<"-1\n";return 0;}
	if (n == 1) {
		if(k == 1) {
			cout << -1 << endl;
			return 0;
		}
		cout << "0 0 1 1" << endl;
		return 0;
	}
	for(ll i=0;i<(1<<n);i++) if(i!=k) cout << i << " ";
	cout << k << " ";
	for(ll i=(1<<n)-1;i>=0;i--) if(i!=k)cout<< i << " ";
	cout << k << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll l,r;
	cin>>l>>r;
	if(l%r==0){
		cout << -1;
		return 0;
	}
	cout << l;
	return 0;
}
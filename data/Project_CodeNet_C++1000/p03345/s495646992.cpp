#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli a, b, c, k;

int main(void){
	cin >> a >> b >> c >> k;
	if(k%2 == 0) cout << a-b << endl;
	else cout << b-a << endl;
	return 0;
}

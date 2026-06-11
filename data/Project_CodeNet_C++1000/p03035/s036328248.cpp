#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll a,b;
	cin>>a>>b;
	if(a>=13){
		cout << b;
	}
	else if(a<=5){
		cout << 0;
	}
	else{
		cout << b/2;
	}
	// your code goes here
	return 0;
}
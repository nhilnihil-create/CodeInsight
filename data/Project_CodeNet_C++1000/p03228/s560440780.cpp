#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b,k;
	cin>>a>>b>>k;
	for(int i=0;i<k;i++){
		a=a/2;
		b=b+a;
		swap(a,b);
	}
	if(k%2!=0){
		swap(a,b);
	}
	cout << a << " " << b;
	// your code goes here
	return 0;
}
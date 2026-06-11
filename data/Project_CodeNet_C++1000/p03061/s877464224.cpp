#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b){
	if( a < b) return gcd(b,a);
	if(b == 0) return a;
	if(b == 1) return 1;
	return gcd(b,a%b);
}

int main()
{
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];
	vector<ll> left(n);
	vector<ll> right(n);
	left[0] = a[0];
	for(int i = 1; i < n; i++){
		left[i] = gcd(left[i-1],a[i]);
	}
	right[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
		right[i] = gcd(right[i+1],a[i]);
	}
	ll ans = 0;
	ans = max(left[n-2],right[1]);
	for(int i = 1; i < n-1; i++){
		ll temp = gcd(left[i-1],right[i+1]);
		ans = max(ans,temp);
	}
	cout<<ans<<endl;
	/*rep(i,n){
		cout<<left[i]<<" ";
	}
	cout<<endl;*/
	return 0;
}

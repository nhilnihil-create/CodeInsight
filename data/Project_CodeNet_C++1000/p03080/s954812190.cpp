#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,r=0,b=0;
	char x;
	cin>>n;
	while(n--){
		cin>>x;
		(x=='R')?r++:b++;
	}
	cout<<((r>b)?"Yes":"No");
	return 0;
}
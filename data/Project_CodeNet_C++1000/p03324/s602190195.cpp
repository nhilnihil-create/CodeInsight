#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int f(int n){
	if( n % 2 == 0){
		return n / 2;
	}else{
		return (3*n) + 1;
	}
}

int main()
{
	ll D,N;
	cin>>D>>N;
	ll num;
	if( D == 0){
		num = 1;
	}else if( D == 1){
		num = 100;
	}else{
		num = 10000;
	}
	ll ans;
	if( N == 100){
		ans = num*101;
	}else{
		ans = num*N;
	}
	cout<<ans<<endl;
	return 0;
}


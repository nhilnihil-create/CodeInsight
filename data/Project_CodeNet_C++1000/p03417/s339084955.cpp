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
typedef long long int ll;

int main()
{
	ll m,n;
	cin>>m>>n;
	ll ans;
	if( m == 1 && n == 1){
		ans = 1;
	}else if( m == 1 || n == 1){
		ll l = min(m,n);
		ll k = max(m,n);
		ans = k - 2;
	}else if( m > 1 && n > 1){
		ans = m*n - 2*(m + n - 2);
	}
	cout<<ans<<endl;
	return 0;
}


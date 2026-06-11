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

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	ll ans = 0;
	int maxValue = 0;
	rep(i,n){
		cin>>a[i];
		ans += a[i];
		maxValue = max(maxValue,a[i]);
	}
	ans -= (maxValue/2);
	cout<<ans<<endl;
	return 0;
}

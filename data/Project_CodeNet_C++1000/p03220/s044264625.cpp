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
	double diff = 1000000000;
	int n;
	double t,a;
	cin>>n;
	cin>>t>>a;
	int ans = 0;
	for(int i = 0; i < n; i++){
		double x;
		cin>>x;
		if( diff > abs(a- (t- x * 0.006))){
			diff = abs(a - (t - x * 0.006));
			ans = i + 1;
		}

	}
	cout<<ans<<endl;
	return 0;
}

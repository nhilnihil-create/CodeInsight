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


int main()
{
	int n;
	cin>>n;
	vector<ll> l(n);
	ll sum = 0;
	ll lmax = 0;
	for(int i = 0 ; i < n; i++){
		cin>>l[i];
		sum += l[i];
		lmax = max(lmax,l[i]);
	}
	sum = sum - lmax;
	if( sum > lmax){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

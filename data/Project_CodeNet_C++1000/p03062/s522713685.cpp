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
int main()
{
	int n;
	cin>>n;
	vector<ll> A(n);
	for(int i = 0; i < n;i++){
		cin>>A[i];
	}
	
	ll sum = 0;
	ll sum1 = A[0] + A[1];
	ll sum2 = -A[0] - A[1];
	for(int i = 2; i < n; i++){
		ll temp1 = sum1;
		ll temp2 = sum2;
		sum1 = max(temp1 + A[i],temp2 + A[i]);
		sum2 = max(temp1 - 2*A[i-1] - A[i],temp2 + 2*A[i-1] - A[i]);
		//cout<<i<<" "<<sum1<<" "<<sum2<<endl;
	}
	sum = max(sum1,sum2);
	cout<<sum<<endl;
	return 0;
}


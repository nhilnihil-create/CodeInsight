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
typedef unsigned long long ll;


int main()
{
	int n;
	cin>>n;
	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	rep(i,n) cin>>A[i];
	rep(i,n) cin>>B[i];
	rep(i,n) cin>>C[i];
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	ll ans = 0;
	rep(i,n){
		auto left = lower_bound(A.begin(),A.end(),B[i]) - A.begin();
		auto right = C.end() -  upper_bound(C.begin(),C.end(),B[i]);
		ans += right * left;
	}
	cout<<ans<<endl;
	return 0;
}


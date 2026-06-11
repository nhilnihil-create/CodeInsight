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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
	int n;
	int sum1 = 0;
	int sum2 = 0;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i = 0; i < n; i++){
		if( i % 2 == 0){
			sum1 += a[i];
		}else{
			sum2 += a[i];
		}
	}
	cout<<sum1 - sum2<<endl;
	return 0;
}


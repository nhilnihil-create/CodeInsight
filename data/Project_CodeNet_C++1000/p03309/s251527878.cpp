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
	int n;
	double b;
	cin>>n;
	int *a = new int[n];
	int *B = new int[n];
	rep(i,n){
		cin>> a[i];
		B[i] = a[i] - (i+1);
	}
	sort(B,B+n);
	//rep(i,n)cout<<B[i]<<" ";
	//cout<<endl;
	if( n % 2 == 0){
		b = ( B[n/2] + B[(n/2)-1])/2;
	}else{
		b = B[ (n-1)/2];
	}
	//cout<<b<<endl;
	int b1,b2;
	b1 = ceil(b);
	b2 = floor(b);
	ll sum1 = 0,sum2 = 0;
	for(int i = 0; i < n; i++){
		sum1 += abs( a[i] - (i+1+b1));
		sum2 += abs( a[i] - (i+1+b2));
	}
	cout<<min(sum1,sum2)<<endl;
	//cout<<"sum1:"<< sum1<<" sum2:"<<sum2<<endl;
	return 0;
}


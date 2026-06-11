#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long ll;

int ceil10(int num){
	int a,b;
	a = num / 10;
	b = num % 10;
	if( b == 0){
		b = 0;
	}else{
		b = 10;
	}
	return 10*a + b;	
}

int main()
{
	int a[5];
	rep(i,5) cin>>a[i];
	int ans = 100000000;
	int sum = 0;
	rep(i,5) sum += ceil10(a[i]);
	rep(i,5) ans = min(ans,sum - ceil10(a[i]) + a[i]);
	cout<<ans<<endl;
	return 0;
}


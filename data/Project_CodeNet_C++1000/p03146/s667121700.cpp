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
	int s;
	cin>>s;
	set<int> numList;
	numList.insert(s);
	int ans = 1;
	s = f(s);
	while( numList.count(s) == 0){
		numList.insert(s);
		s = f(s);
		ans++;
	}
	cout<<ans+1<<endl;
	return 0;
}


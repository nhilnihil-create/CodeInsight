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
	vector<int> d(n);
	rep(i,n){
		cin>>d[i];
	}
	sort(d.begin(),d.end(),greater<int>());
	int ans = 1;
	int currentD = d[0];
	for(int i = 1; i < n; i++){
		if(currentD > d[i]) ans++;
		currentD = d[i];
	}
	cout<<ans<<endl;
	return 0;
}


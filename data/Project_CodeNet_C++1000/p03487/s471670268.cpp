#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
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
	map<int,int> numMap;
	cin>>n;
	rep(i,n){
		int a;
		cin>>a;
		if( numMap.count(a) == 0){
			numMap.insert(make_pair(a,1));
		}else{
			numMap[a]++;
		}
	}
	int ans = 0;
	for(auto iter = numMap.begin(); iter != numMap.end(); iter++){
		int key,value;
		key = iter->first;
		value = iter->second;
		if( value >= key){
			ans += value - key;
		}else{
			ans += value;
		}
	}
	cout<<ans<<endl;
	return 0;
}


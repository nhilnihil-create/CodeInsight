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
	int n,m;
	cin>>n;
	map<string,int> blue;
	for(int i = 0 ; i < n ; i++){
		string str;
		cin>>str;
		if( blue.count(str) == 0){
			blue[str] = 1;
		}else{
			blue[str]++;
		}
	}
	cin>>m;
	map<string,int> red;
	for(int i = 0; i < m ; i++){
		string str;
		cin>>str;
		if( red.count(str) == 0){
			red[str] = 1;
		}else{
			red[str]++;
		}
	}
	int	ans = 0;
	for(auto iter = blue.begin(); iter != blue.end(); iter++){
		int b,r;
		b = iter->second;
		r = 0;
		if( red.count(iter->first) != 0) r = red[iter->first];
		ans = max(ans, b - r);
	}
	cout<<ans<<endl;
	return 0;
}

